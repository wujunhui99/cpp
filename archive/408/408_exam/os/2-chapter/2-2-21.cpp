semaphore empty = 100;//
semaphore full = 0;
semaphore mutex1 = 1;
semaphore mutex2 = 1;
Producer(){
	P(empty);
	P(mutex1);
	make();
	V(mutex1);
	V(full);
}
consumer(){
	while(true){

		P(mutex2);
		for(int i = o;i<10;i++){

			P(full);	
			P(mutex1);
			get();
			V(mutex1);
			V(empty);
		}
		V(mutex2);
	}
}

