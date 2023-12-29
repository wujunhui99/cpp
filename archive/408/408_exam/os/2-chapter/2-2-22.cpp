semaphore mutex_A = 1, mutex_B = 1; //互斥使用信箱A和B的信号量
semaphore full_A = x,full_B = y;//信箱信的数量
semaphore empty_A = M - x, empty_B = N - y;//
A(){
	while(true){
		P(full_A);
		P(mutex_A);
		xxx;
		V(mutex_A);
		V(empty_A);

		xxx;
		P(empty_B);
		P(mutex_B);
		xxx;
		V(mutex_B);
		V(full_B);
	}
	}
