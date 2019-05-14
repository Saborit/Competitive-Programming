// -- aumentar la memoria de la stack,
// func debe ser declarada static (e.g., static void main2)

static void run_with_stack_size(void (*func)(), size_t stsize) {
	char *stack, *send;
	stack=(char *)malloc(stsize);
	send=stack+stsize-16;
	send=(char *)((uintptr_t)send/16*16);
	
	asm volatile(
		"mov %%rsp, (%0)\n"
		"mov %0, %%rsp\n"
		:
		: "r" (send));
	func();
	
	asm volatile(
		"mov (%0), %%rsp\n"
		:
		: "r" (send));
	free(stack);
}

void main2(){
	cout << dfs() << endl;
}

int main()
{
  run_with_stack_size(main2, 1 << 30);
}
