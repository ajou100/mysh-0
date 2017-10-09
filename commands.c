#include <string.h>
#include <unistd.h> // getcwd(,)사용
#include <stdio.h> // stderr사용
#include "commands.h"

int do_cd(int argc, char** argv)   // argv : 파싱된 2차원 배열
{
  if (!validate_cd_argv(argc, argv))
    return -1;


  if (strcmp(argv[1] == '.'))  // .일 때 현재주소에 머문다.
  {
	  // 아무것도 안함
  }
  else if (strcmp(argv[1] == '..'))  // ..일 때 상위주소로 이동
  {
	  char ar[8000];
	  getcwd(ar, 8000); // 현재 주소를 최대 8000크기로 ar에 저장

	  int lastindex;
	  for (int i = 0; ar[i] != 0; i++)   //  마지막w 앞에 있는 주소가 상위 주소
	  {								   //  aaaaa\bbbbbb\zzzz\1234567 : aaaaa\bbbbbb\zzzz 가 상위주소
		  if (ar[i] == '\'')
		  {
			  lastindex=i; // \만날 때마다 해당 \의 위치를 인덱스로 저장
		  }
	  }

	  char *ar2;
	  strncpy(at2, ar, lastindex + 1);
	  chdir(ar2);

	  //잘라준 주소구현
	  //이미 root일 떄 execption 처리
	  
  }
  else if (stcmp(argv[1][0] == '\'' )  )   //  절대주소일 때 
	  //절대주소는 \로 시작한다. 읽어드린 파싱의 맨 처음이 \인지 확인
  {
	  chdir(argv[1]);  // argv[1]로 디렉토리 이동

	  // 주소가 존재하지 않을 때 exeption 처리
  }
  else  //  argc[1]이 상대주소일 때
  {
	  char ar[8000];   
	  getcwd(ar, 8000);  // 현재주소 받는다.

	  char ar2[8000];
	  strcpy(ar2, ar);
	  
	  // 절대주소 : 현재주소\상대주소
	  ar2[ar.size()] = '\''; // 현재주소 끝에 \ 추가
	  strcpy(ar2 + ar.size() + 1, argc[1]); // 현재주소\ 에 상대주소 추가
	  
	  // 주소 존재하지 않을 때 execption처리

	  chdir(ar2);  // ar2로 디렉토리 이동
  }



  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv)   // 현재 주소 보여주기
{
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char ar[8000];
  getcwd(ar, 8000); // 최대 8000의 현재 주소를 문자열 ar에 저장

  fprintf(stdout, ar);


  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if (argc != 2)  // cd는 조각 2개여야 한다.
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
	if (argc != 1)  // pwd는 1개여야 한다.
	{
		return 0;
	}
	else if(strcmp(argv[0], "pwd") == 0) // argv[0]이 pwd가 아니면  (TEST함수 EST(CDValidateTest, ValidateCDArgv4))
	{
		return 0;  //false 
	}

  // TODO: Fill it!
  return 1;
}
