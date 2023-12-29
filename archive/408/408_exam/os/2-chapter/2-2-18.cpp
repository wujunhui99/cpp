semaphore odd = 0, even = 0, empty = N, mutex = 1;
cobegin{
	Process P1(){
		while(true){
			int x = produce();
			P(empty);
			P(mutex);
			Put();
			V(mutex);
			if(x % 2)
				V(odd);
			else
				V(even);
		}
	}
	Process P2(){
		while(true){
			P(odd);
			P(mutex);
			getodd();
			V(mutex);
			V(empty);
			countodd();
		}
	}
	Process P3(){
		while(true){
			P(even);
			P(mutex);
			geteven();
			V(mutex);
			V(empty);
			counteven();
		}
	}
}coend


