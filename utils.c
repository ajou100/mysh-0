#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv) // argc:������ ����
{
	//command �� ���۷� ����

	*argc = 1;  // *argc : ó�� ���� �� 1���� ������

	for (int i = 0; i < 8096; i++) // ���ڸ� 1���� �о����.
	{
		if (command[i] == 0) // �������� �������� ��
			break;

		

		if (command[i] == ' ') // ��ĭ ������
		{
			*argc++; // ��ū(����) ���� ����
		}
		else
		{
			*argv[argc - 1] += command[i];  // �ش� ������ �о�帰 ���� �߰�
		}
		
	
	}


  // TODO: Fill this!
}
