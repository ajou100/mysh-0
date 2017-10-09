#include <string.h>
#include <unistd.h> // getcwd(,)���
#include <stdio.h> // stderr���
#include "commands.h"

int do_cd(int argc, char** argv)   // argv : �Ľ̵� 2���� �迭
{
  if (!validate_cd_argv(argc, argv))
    return -1;


  if (strcmp(argv[1] == '.'))  // .�� �� �����ּҿ� �ӹ���.
  {
	  // �ƹ��͵� ����
  }
  else if (strcmp(argv[1] == '..'))  // ..�� �� �����ּҷ� �̵�
  {
	  char ar[8000];
	  getcwd(ar, 8000); // ���� �ּҸ� �ִ� 8000ũ��� ar�� ����

	  int lastindex;
	  for (int i = 0; ar[i] != 0; i++)   //  ������w �տ� �ִ� �ּҰ� ���� �ּ�
	  {								   //  aaaaa\bbbbbb\zzzz\1234567 : aaaaa\bbbbbb\zzzz �� �����ּ�
		  if (ar[i] == '\'')
		  {
			  lastindex=i; // \���� ������ �ش� \�� ��ġ�� �ε����� ����
		  }
	  }

	  char *ar2;
	  strncpy(at2, ar, lastindex + 1);
	  chdir(ar2);

	  //�߶��� �ּұ���
	  //�̹� root�� �� execption ó��
	  
  }
  else if (stcmp(argv[1][0] == '\'' )  )   //  �����ּ��� �� 
	  //�����ּҴ� \�� �����Ѵ�. �о�帰 �Ľ��� �� ó���� \���� Ȯ��
  {
	  chdir(argv[1]);  // argv[1]�� ���丮 �̵�

	  // �ּҰ� �������� ���� �� exeption ó��
  }
  else  //  argc[1]�� ����ּ��� ��
  {
	  char ar[8000];   
	  getcwd(ar, 8000);  // �����ּ� �޴´�.

	  char ar2[8000];
	  strcpy(ar2, ar);
	  
	  // �����ּ� : �����ּ�\����ּ�
	  ar2[ar.size()] = '\''; // �����ּ� ���� \ �߰�
	  strcpy(ar2 + ar.size() + 1, argc[1]); // �����ּ�\ �� ����ּ� �߰�
	  
	  // �ּ� �������� ���� �� execptionó��

	  chdir(ar2);  // ar2�� ���丮 �̵�
  }



  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv)   // ���� �ּ� �����ֱ�
{
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char ar[8000];
  getcwd(ar, 8000); // �ִ� 8000�� ���� �ּҸ� ���ڿ� ar�� ����

  fprintf(stdout, ar);


  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if (argc != 2)  // cd�� ���� 2������ �Ѵ�.
	{
		return 0;
	}
	else if (!(strcmp(atgv[0]), "cd") == 0)
	{
		return 0;
	}


  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
	if (argc != 1)  // pwd�� 1������ �Ѵ�.
	{
		return 0;
	}
	else if(strcmp(argv[0], "pwd") == 0) // argv[0]�� pwd�� �ƴϸ�  (TEST�Լ� EST(CDValidateTest, ValidateCDArgv4))
	{
		return 0;  //false 
	}

  // TODO: Fill it!
  return 1;
}
