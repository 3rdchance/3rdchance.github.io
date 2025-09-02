#include <unistd.h>
#include <stdio.h>


// case 1 "-o:"
// Test1 support this -o abc format or only support -oabc
// Answer1:
//       aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$ ./a.out  -oabc
//       optarg : abc
//       aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$ ./a.out  -o abc
//       optarg : abc
// Test2 permute all argv, all not option element put to last ?
// Answer2: No
//	aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$ ./a.out  x -op  1 2 3 4
//	not support 1
//	optarg : p
//	not support 1
//	not support 1
//	not support 1
//	not support 1
//	after getopt parse optind 7 argc 7
// Test3 optional argument format "o:n:: can only support -nabc not support -n abc
// Two colons mean an option  takes  an optional arg; if there is text in the current argv-element (i.e., in the same word as the option name itself, for example, "-oarg"), then it is returned in optarg, otherwise optarg is set to zero.
// Answer2: yes
// aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$ ./a.out  -n100
//	option n's argument 100
//	after getopt parse optind 2 argc 2
//aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$ ./a.out  -n 100
//	option n no argument

// 
// case 2: "o:"
// argv permuted
// aaa@aaa-OptiPlex-7080:~/Downloads/3rdchance.github.io/code$  ./a.out  x -op  1 2 3 4
//	optarg : p
//	after getopt parse optind 2 argc 7
//	optindex 2 argv[optindex] x
//	optindex 3 argv[optindex] 1
// 	optindex 4 argv[optindex] 2
//	optindex 5 argv[optindex] 3
// 	optindex 6 argv[optindex] 4

int main(int argc ,char** argv)
{
	int opt;
	while ((opt = getopt(argc, argv, "o:n::")) != -1) {
		switch (opt) {
		case  'o':
			printf ("option o's argument : %s\n", optarg);
			break;
		case 'n':
			if (optarg != NULL)
				printf("option n's argument %s\n", optarg);
			else 
				printf("option n no argument\n");
			break;
		default:
			printf("not support %d\n", opt);
		}
	}

	printf("after getopt parse optind %d argc %d\n", optind, argc);

	while (optind < argc) {
		printf("optindex %d argv[optindex] %s\n", optind, argv[optind]);
		optind++;
	
	}

	return 0;
}
