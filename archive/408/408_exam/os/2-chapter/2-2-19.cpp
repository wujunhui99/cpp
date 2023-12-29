semaphore service = 0, seat = 10; 
semaphore mutex = 1; //
semaphore full = 0;//取得号码等待叫号的顾客
Proccess custom-i(){
	P(seat);
	P(mutex);
	//取号
	V(mutex);
	V(full);
	P(service);
}
Process assistant(){
	P(full);
	//service
	V(seat);
	V(service);
}
