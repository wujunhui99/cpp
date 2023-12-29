semaphore offer1 = 0,offer2 = 0,offer3 = 0;
semaphore finish = 0;

provider(){
	while(1){
	int i = random()%3；
	if(i == 0)
		V(offer1);
	if(i == 1)
		V(offer2);
	if(i == 2)
		V(offer3);
	P(finish);}
}
fan1(){
	P(offer1);
	听歌;
	V(finish);
}
fan2(){
	P(offer2);
	听歌;
	V(finish);
}
fan3(){
	P(offer3);

	听歌;
	V(finish);
}
