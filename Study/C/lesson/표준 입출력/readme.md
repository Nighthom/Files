# 표준 입출력


표준 입력장치 = stdin(keyboard)  
표준 출력장치 = stdout(console)  

표준 입출력은 유저 영역에서 커널 영역으로 사용을 요청합니다.  
만약 입력을 요청한다면 표준 입력장치인   
하드웨어 키보드로부터 입력을 받겠죠?  
하드웨어가 신호를 전달하면 커널 영역은 이를 입력값으로 전환합니다.  
그리고 입력 버퍼에 입력을 쌓습니다. 버퍼는 큐로 구성되어 있습니다.  
만약 유저 영역에서 이 표준 입력 버퍼를 요청한다면,  
커널 영역에서 유저 영역으로 입력값을 stdin 버퍼로(stdin 버퍼는 파일로 구성되어 있어요.)  
값을 올려줍니다.  
그러면 유저는 상황에 맞게 이 stdin버퍼를 활용해서   
getchar, gets, scanf 등의 함수로 적절한 값을 가져오는 원리입니다.  

표준 출력장치는 콘솔입니다. 만약 유저모드의 소프트웨어가 stdout 버퍼에  
출력하고자 하는 데이터를 보내고 커널에 출력을  
요청한다면, 커널은 stdout 버퍼를 출력 버퍼로 가져갑니다.  
그리고 콘솔로 출력을 보내죠.   
printf, puts, putchar같은 함수가 바로 출력 함수입니다.  

이런 표준 입출력에 관한 함수들은 바로 stdio(standard input and output)  
헤더파일에 정의되어 있습니다.  

다음은 표준입력함수, 표준출력함수의 상세 API입니다.

  1. [표준입력함수](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%91%9C%EC%A4%80%20%EC%9E%85%EC%B6%9C%EB%A0%A5/%ED%91%9C%EC%A4%80%EC%9E%85%EB%A0%A5%ED%95%A8%EC%88%98.md)
  2. [표준출력함수](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%91%9C%EC%A4%80%20%EC%9E%85%EC%B6%9C%EB%A0%A5/%ED%91%9C%EC%A4%80%EC%B6%9C%EB%A0%A5%ED%95%A8%EC%88%98.md)
  3. [getch, getche](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%91%9C%EC%A4%80%20%EC%9E%85%EC%B6%9C%EB%A0%A5/getch%2C%20getche)

그리고, 포맷 스트링을 사용하는 함수들을 위한 포맷 스트링 상세입니다.  
    4. [포맷 스트링](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%91%9C%EC%A4%80%20%EC%9E%85%EC%B6%9C%EB%A0%A5/%ED%8F%AC%EB%A7%B7%20%EC%8A%A4%ED%8A%B8%EB%A7%81.md) 
    
  stdin 버퍼에 개행문자가 차서 gets, getchar, scanf함수를 통하여  
  문자를 제대로 가져올 수 없다면  
  5. [stdin 버퍼 비우기](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%91%9C%EC%A4%80%20%EC%9E%85%EC%B6%9C%EB%A0%A5/stdin%20%EB%B2%84%ED%8D%BC%20%EB%B9%84%EC%9A%B0%EA%B8%B0.md)  
  를 참조하세요.  
 
 [이전 페이지](https://github.com/Nighthom/Files/tree/main/Study/C/lesson/%EA%B8%B0%EB%B3%B8%EC%9D%B4%EB%A1%A0)  
 [목차로 돌아가기](https://github.com/Nighthom/Files/tree/main/Study/C)  
 [다음 페이지](https://github.com/Nighthom/Files/tree/main/Study/C/lesson/%EC%A1%B0%EA%B1%B4%EB%B6%84%EA%B8%B0%EB%AC%B8)
