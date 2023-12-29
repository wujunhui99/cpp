semaphore mutex = 1; //mutex
semaphore empty = 500; //still container
cobgin
Process i
{
	P(empty); // 
	P(mutex);
	enter();
	V(mutex);


	P(mutex);
	exit();
	V(mutex);
	V(empty);
}

