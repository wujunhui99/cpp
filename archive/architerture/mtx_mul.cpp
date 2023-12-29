#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <immintrin.h>
#include <thread>
using namespace std;

vector<vector<int>> readMtx(string filename, int &rows, int &cols)
{
	ifstream file(filename);
	string line;
	file >> rows >> cols;
	vector<vector<int>> mat(rows, vector<int>(cols));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::string val;
			file >> val;
			stringstream ss(val);
			ss >> mat[i][j];
		}
	}
	file.close();
	return mat;
}

vector<vector<int>> mtx_mul(vector<vector<int>> &mtx1, vector<vector<int>> &mtx2)
{
	int row = mtx1.size();
	int col = mtx2[0].size();
	vector<vector<int>> ret(row, vector<int>(col));
	int adds = mtx2.size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int tmp = 0;
			for (int k = 0; k < adds; k++)
			{
				tmp += mtx1[i][k] * mtx2[k][j];
			}
			ret[i][j] = tmp;
		}
	}
	return ret;
}

vector<vector<int>> mtx_mul_cache(vector<vector<int>> &mtx1, vector<vector<int>> &mtx2)
{
	int m = mtx2.size();
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			swap(mtx2[i][j], mtx2[j][i]);
		}
	}
	int row = mtx1.size();
	int col = mtx2[0].size();
	vector<vector<int>> ret(row, vector<int>(col));
	int adds = mtx2.size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int tmp = 0;
			for (int k = 0; k < adds; k++)
			{
				tmp += mtx1[i][k] * mtx2[j][k];
			}
			ret[i][j] = tmp;
		}
	}
	return ret;
}

vector<vector<int>> mtx_mul_cache_simd(vector<vector<int>> &mtx1, vector<vector<int>> &mtx2)
{
	int m = mtx2.size();
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			swap(mtx2[i][j], mtx2[j][i]);
		}
	}
	int row = mtx1.size();
	int col = mtx2[0].size();
	vector<vector<int>> ret(row, vector<int>(col));
	int adds = mtx2.size();
	__m256i a,b,c;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int tmp = 0, sum = 0;
			for (int k = 0; k < adds; k+=8)
			{
				a = _mm256_loadu_si256((__m256i*) &mtx1[i][k]);
				b = _mm256_loadu_si256((__m256i*) &mtx2[j][k]);
				c = _mm256_mullo_epi32(a,b);
				tmp += (_mm256_extract_epi32(c, 0) + _mm256_extract_epi32(c, 1) + _mm256_extract_epi32(c, 2) + _mm256_extract_epi32(c, 3) + _mm256_extract_epi32(c, 4) + _mm256_extract_epi32(c, 5) + _mm256_extract_epi32(c, 6) + _mm256_extract_epi32(c, 7)); 
			}
			ret[i][j] = tmp;
		}
		
	}
	return ret;
}


vector<vector<int>> mtx_mul_cache_simd_core(vector<vector<int>> &mtx1, int row1,int col1 , vector<vector<int>> &mtx2, int row2,int col2, int sub_m, vector<vector<int>> &ret){
	int adds = sub_m;
	__m256i a,b,c;
	for (int i = 0; i < sub_m; i++)
	{
		for (int j = 0; j < sub_m; j++)
		{
			int tmp = 0;
			for (int k = 0; k < adds; k+=8)
			{
				a = _mm256_loadu_si256((__m256i*) &mtx1[row1 + i][col1 + k]);
				b = _mm256_loadu_si256((__m256i*) &mtx2[j+row2][k+col2]);
				c = _mm256_mullo_epi32(a,b);
				tmp += (_mm256_extract_epi32(c, 0) + _mm256_extract_epi32(c, 1) + _mm256_extract_epi32(c, 2) + _mm256_extract_epi32(c, 3) + _mm256_extract_epi32(c, 4) + _mm256_extract_epi32(c, 5) + _mm256_extract_epi32(c, 6) + _mm256_extract_epi32(c, 7));  
			}
			ret[i][j] = tmp;
		}
		
	}
	return ret;
}
vector<vector<int>> addVectors(const vector<vector<int>>& v1, const vector<vector<int>>& v2) {
  vector<vector<int>> result(v1.size(), vector<int>(v1[0].size()));
  for (size_t i = 0; i < v1.size(); i++) {
    for (size_t j = 0; j < v1[0].size(); j++) {
      result[i][j] = v1[i][j] + v2[i][j];
    }
  }
  return result;
}

vector<vector<int>> mtx_mul_cache_simd_cores(vector<vector<int>> &mtx1, vector<vector<int>> &mtx2){
	int m = mtx2.size();
	for (int i = 0; i < m; i++) for(int j = i + 1; j < m; j++)	swap(mtx2[i][j], mtx2[j][i]);
	int row = mtx1.size();
	int col = mtx2[0].size();
	vector<vector<int>> ret(row, vector<int>(col));
	vector<vector<int>> a1(row/2,vector<int>(col/2,0));
	vector<vector<int>> b2(row/2,vector<int>(col/2,0));
	vector<vector<int>> a3(row/2,vector<int>(col/2,0));
	vector<vector<int>> b4(row/2,vector<int>(col/2,0));
	vector<vector<int>> c1(row/2,vector<int>(col/2,0));
	vector<vector<int>> d2(row/2,vector<int>(col/2,0));
	vector<vector<int>> c3(row/2,vector<int>(col/2,0));
	vector<vector<int>> d4(row/2,vector<int>(col/2,0));
	thread t0(mtx_mul_cache_simd_core, std::ref(mtx1), 0,				0,	std::ref(mtx2),0,0,	mtx1.size()/2,std::ref(a1)); 
	thread t1(mtx_mul_cache_simd_core, std::ref(mtx1), 0,				mtx1.size()/2,ref(mtx2),0,mtx1.size()/2,	mtx1.size()/2,ref(b2)); 
	thread t2(mtx_mul_cache_simd_core, std::ref(mtx1), 0,				0,ref(mtx2),mtx1.size()/2,	0,	mtx1.size()/2,ref(a3)); 
	thread t3(mtx_mul_cache_simd_core, std::ref(mtx1), 0,				mtx1.size()/2,ref(mtx2),mtx1.size()/2,mtx1.size()/2,mtx1.size()/2,ref(b4)); 
	thread t4(mtx_mul_cache_simd_core, std::ref(mtx1), mtx1.size()/2,	0,ref(mtx2),0,0,mtx1.size()/2,ref(c1)); 
	thread t5(mtx_mul_cache_simd_core, std::ref(mtx1), mtx1.size()/2,	mtx1.size()/2,ref(mtx2),0,mtx1.size()/2,mtx1.size()/2,ref(d2)); 
	thread t6(mtx_mul_cache_simd_core, std::ref(mtx1), mtx1.size()/2,	0,ref(mtx2),mtx1.size()/2,0,mtx1.size()/2,ref(c3)); 
	thread t7(mtx_mul_cache_simd_core, std::ref(mtx1), mtx1.size()/2,	mtx1.size()/2,ref(mtx2),mtx1.size()/2,	mtx1.size()/2,mtx1.size()/2,ref(d4)); 
	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	auto lu = addVectors(a1,b2);
	auto ru = addVectors(a3,b4);
	auto ld = addVectors(c1,d2);
	auto rd = addVectors(c3,d4);
	int n = lu.size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ret[i][j] = lu[i][j];
			ret[i][j+n] = ru[i][j]; 
			ret[i+n][j] = ld[i][j];
			ret[i+n][j+n] = rd[i][j];
		}
}
	return ret;
}  
using FuncPtr = vector<vector<int>> (*)(vector<vector<int>> &mtx1, vector<vector<int>> &mtx2);
int time_count( FuncPtr fp, vector<vector<int>> &mtx1, vector<vector<int>> &mtx2){
	auto prev = std::chrono::steady_clock::now();
	auto prev_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(prev);
	auto past_val = prev_ms.time_since_epoch().count();
	auto ret = fp(mtx1,mtx2);
	cout << ret[0][0] <<endl;
	cout << ret[512][512] << endl;
	auto now = std::chrono::steady_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto now_val = now_ms.time_since_epoch().count();
	return now_val - past_val;
}
int test(){
	int rows1, cols1;
	auto mat1 = readMtx("mtx1.txt", rows1, cols1);
	int rows2, cols2;
	auto mat2 = readMtx("mtx2.txt", rows2, cols2);
	auto raw = mtx_mul(mat1,mat2);
	auto cache = mtx_mul_cache(mat1,mat2);


	mat2 = readMtx("mtx2.txt", rows2, cols2);
	auto simd = mtx_mul_cache_simd(mat1,mat2);	

	mat2 = readMtx("mtx2.txt", rows2, cols2);
	auto cores = mtx_mul_cache_simd_cores(mat1,mat2);
	for(int i =0;i<1024;i++) cout << i << endl;
	
	return 0;
}
int app_start(){
	
	int rows1, cols1;
	auto mat1 = readMtx("mtx1.txt", rows1, cols1);
	int rows2, cols2;
	auto mat2 = readMtx("mtx2.txt", rows2, cols2);
	cout << "raw : "<<time_count(mtx_mul,mat1,mat2)<<" ms" << endl;

	cout << "cache "<<time_count(mtx_mul_cache,mat1,mat2)<<" ms"<<endl;

	mat2 = readMtx("mtx2.txt", rows2, cols2);
	cout << "simd "<<time_count(mtx_mul_cache_simd,mat1,mat2)<<" ms"<<endl;	

	// mat2 = readMtx("mtx2.txt", rows2, cols2);
	// cout << "cores "<<time_count(mtx_mul_cache_simd_cores,mat1,mat2)<<" ms"<<endl;	
	return 0;
}
int cmp_gpu(){
	int rows1, cols1;
	auto mat1 = readMtx("n1.txt", rows1, cols1);
	int rows2, cols2;
	auto mat2 = readMtx("n2.txt", rows2, cols2);
	cout << "cores "<<time_count(mtx_mul_cache_simd_cores,mat1,mat2)<<" ms"<<endl;	
	return 0;
}
int main(int argc, char const *argv[])
{
	app_start();
}
