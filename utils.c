#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv) // argc:조각의 갯수
{
	//command 는 버퍼로 사용됨

	*argc = 1;  // *argc : 처음 받은 건 1개의 뭉텅이

	for (int i = 0; i < 8096; i++) // 문자를 1개씩 읽어나간다.
	{
		if (command[i] == 0) // 마지막에 도달했을 때
			break;

		

		if (command[i] == ' ') // 빈칸 만나면
		{
			*argc++; // 토큰(조각) 갯수 증가
		}
		else
		{
			*argv[argc - 1] += command[i];  // 해당 조각에 읽어드린 문자 추가
		}
		
	
	}


  // TODO: Fill this!
}
