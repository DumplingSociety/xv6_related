void main () 
{
	char* videoram = (char*)0xb8000;

	*((int*)0xb8000) = 0x4f;
	*((int*)0xb8001) = 0x0f;
	*((int*)0xb8002) = 0x4b; 	
	*((int*)0xb8003) = 0x0f; 	

	for(;;); //infinite loop
}
