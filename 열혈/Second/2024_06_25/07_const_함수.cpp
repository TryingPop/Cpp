/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : const 함수
	교재 p158 ~ 160

	Rectangle.h에 선언된 함수들에는 const 선언이 추가되었다
	이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다고 알리는 키워드다

	const 선언이 추가된 멤버함수 내에 멤버변수의 값을 변경하는 코드가 삽입되면,
	컴파일 에러가 발생한다

	const로 선언하면, 실수로 자신의 의도와 다르게 멤버변수의 값을 변경했을 때,
	컴파일 에러를 통해서 이를 확인할 수 있다
	이는 프로그래머의 실수를 최소화하기 위한 매우 의미있는 선언이다

	그리고 const 함수 내에서는 const가 아닌 함수의 호출이 제한된다
	const로 선언되지 않은 함수는 아무리 멤버변수에 저장된 값을 변경하지 않더라도,
	변경할 수 있는 능력을 지닌 함수다 따라서 이러한 변경이 가능한 함수의 호출을 하예 허용하지 않는 것이다

	const 선언이 많아지면 코드의 안정성이 높아질 것이다
*/