#include <stdio.h>
#include <stdlib.h>

static int * g_count = NULL;

class Target
{
public:
	Target()
	{
		fprintf(stderr, "Class constructor is called.\n");
	}

	~Target()
	{
		fprintf(stderr, "Class deconstructor is called.\n");
	}
};

__attribute__((constructor)) void before_main()
{
	printf("Function constructor is called in %s.\n", __FUNCTION__);
	g_count = (int *)malloc(sizeof(int));
	if (g_count == NULL)
	{
		fprintf(stderr, "Failed to malloc memory.\n");
	}
}

__attribute__((destructor)) void after_main()
{
	fprintf(stderr, "Function destructor is called in %s.\n", __FUNCTION__);
	if (g_count)
		free(g_count);
}

int main()
{
	Target target;
	fprintf(stderr, "Function main is called in %s.\n", __FUNCTION__);
	return 0;
}
