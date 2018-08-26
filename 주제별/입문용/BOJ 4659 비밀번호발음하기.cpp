/*
백준 온라인 저지 BOJ 4659 비밀번호 발음하기
*/


#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

bool isVowel(char c) {		//returns '1' if c is a vowel
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
string pw;

int main(void) {
	while (1) {
		cin >> pw;		int vowel = 0;	bool flag = true;
		if (pw == "end")
			return 0;
		else {
			for (int i=0; i < pw.length(); i++) {	//끝 두자리
				if (isVowel(pw[i]))
					vowel++;
				if (pw[i] != 'e' && pw[i] != 'o' && (pw[i] == pw[i + 1])) {
					flag = false;
				}
			}

			if (flag && pw.length() >= 3) {
				for (int i = 0; i < pw.length() - 2; i++) {		//pw.length-2까지 (끝 두자리 남음)
					if ( (isVowel(pw[i]) && isVowel(pw[i + 1]) && isVowel(pw[i + 2]))
						|| (!isVowel(pw[i]) && !isVowel(pw[i + 1]) && !isVowel(pw[i + 2])) ) {
						flag = false;
					}
				}
			}

			//최종 처리
			printf("<%s> is ", pw.c_str());
			if (vowel <= 0 || !flag)
				cout << "not acceptable.\n";
			else
				cout << "acceptable.\n";
		}
	}
	return 0;
}



/*
다른 분 코드 좋아서 코트 해둠
아이디: kiteline93

알파벳 모음 자음을 bool 배열 vowel[26]으로 구분하는 방식이 인상적이었음.
printf() 사용에도 fail ? "not" : "" 으로 간략하게 작성한 것도 좋음.
논리가 눈에 확 띄는 형식의 코드인 것도 좋음.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char S[21];
		scanf("%s", S);
		if(strcmp(S, "end") == 0) break;

		bool used[26] = {0}, vused = false, vowel[26] = {0}, fail = false;
		vowel[0] = vowel[4] = vowel[8] = vowel[14] = vowel[20] = true;
		for(int i=0; S[i]; i++){
			used[S[i]-'a'] = true;
			if(vowel[S[i]-'a']) vused = true;
			if(i > 0 && S[i] == S[i-1] && S[i] != 'e' && S[i] != 'o') fail = true;
			if(i > 1 && vowel[S[i]-'a'] == vowel[S[i-1]-'a'] && vowel[S[i]-'a'] == vowel[S[i-2]-'a']) fail = true;
		}
		if(!vused) fail = true;
		printf("<%s> is %sacceptable.\n", S, fail ? "not " : "");
	}
}
