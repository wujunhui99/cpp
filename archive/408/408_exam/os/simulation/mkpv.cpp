Semaphore mutex = 1;
Semphore Smutex = 1;
Semaphore Nmutex = 1;
int S_number = 0;
int N_number = 0;
Process South_mokey{
	P(Smutex);
	if(S_number == 0)
		P(mutex);
	S_number++;
	V(Smutex);
	从南向北过绳子;
	P(Smutex);
	S_number--;
	if(S_number == 0)
		V(mutex);
	V(Smutex);
}
Process North_mokey{
	P(Nmutex);
	if(N_number==0)
		P(mutex);
	N_number++;
	V(Nmutex);
	cross();//通过绳索
	P(Nmutex);
	N_mutex--;
	if(N_mutex==0)
		V(mutex);
	V(N_number);
}
