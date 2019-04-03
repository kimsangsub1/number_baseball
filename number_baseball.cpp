#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    return answer;
}

/*
   vector<vector<int>> chooseStrike(int sequence, int strike_number){
        // i개의 strike 숫자를 선택하여 가능한 숫자를 int vector로 반환한다. 
        // ex) strike_number : 2, sequence : 123 일 때, return : [[1,2],[1,3],[2,3]] 
        입력 수열을 문자 형태로 쪼갠다. ex) 123 -> '1','2','3'
        strike_number를 고려하여 순열을 생성한다. (순서 고려)
        생성한 순열을 이중 벡터에 저장하여 return 한다.

        return strike_arrays;
    }
*/

vector<vector<int>> combination(vector<int> list, int k){
    vector<vector<int>> result;

	// 0과1을 저장 할 벡터 생성
	vector<int> index;

	// k개의 1 추가
	for(int i=0; i<k; i++) index.push_back(1);
	
	// 2개(6개-2개)의 0 추가
	for(int i=0; i<list.size()-k; i++) index.push_back(0);

	//순열
	do{
        vector<int> tmp;
		for(int i=0; i<index.size(); i++)
			if(index[i] == 1)
				tmp.push_back(list[i]);

        result.push_back(tmp);
	}while(next_permutation(index.begin(), index.end()));
    return result;
}

vector<int> changeFormat(int sequence){
    // "123" -> [1,2,3]
    vector<int> tmp;
    for(int i = 0 ; i < 3 ;i++){
        int t = sequence%10;
        sequence /= 10;
        tmp.push_back(t);
    }
    return tmp;
}

vector<vector<int>> chooseStrike(int sequence, int strike_number){
    return combination(changeFormat(sequence), strike_number);
}

// array 에 있는 값들이 sequence에서 어떤 인덱스에 포함되어 있는지 vector<bool> 타입으로 반환한다.
vector<bool> informPosition(int sequence, vector<int> array){ 
    vector<int> sequence_v_type = changeFormat(sequence); // 123 -> [1,2,3]
    vector<bool> possible_check; // strike가 아닌 것은 false
    for(int i = 0 ; i < sequence_v_type.size(); i++) 
        possible_check.push_back(false);

    // sequence : [1,2,3] , strike_array : [2]가 주어질 때, 
    for(int i = 0 ; i< sequence_v_type.size(); i++)
        for(int j = 0 ; j<array.size(); j++)
            if(sequence_v_type[i] == array[j])
                possible_check[i] = true; // array 데이터가 sequence 몇 번째에 있는지를 나타낸다.

    return possible_check;
}
/*
    vector<vector<int>> chooseBall(int sequence, vector<int> strike_array, int ball_number){
        //입력으로 들어온 strike_array와 ball_number를 고려하여 가능한 ball의 조합을 vector 형식으로 표현한다.
        //ex) sequence : 123, strike_array : [1] , ball_number : 1 일때, return : [[2], [3]]
 
        return ball_arrays;
    }
*/
vector<vector<int>> chooseBall(int sequence, vector<int> strike_array, int ball_number){
    // sequence : [1,2,3], strike_array : [2], ball_number : 1 이면, [[1],[3]] 생성
    vector<int> mod_sequence_v_type;
    vector<int> sequence_v_type = changeFormat(sequence);
    vector<bool> ball_possible_check = informPosition(sequence, strike_array);

    for(int i = 0 ; i<sequence_v_type.size(); i++)
        if(ball_possible_check[i] == false)
            mod_sequence_v_type.push_back(sequence_v_type[i]);

    return combination(mod_sequence_v_type, ball_number);
}

typedef struct{
    int position;
    int value;
    char status;
}Info;

vector<Info> totalInformation(int sequence, vector<int> strike_array, vector<int> ball_array){
    /* 모든 정보를 다 담고 있는 벡터 리스트를 반환한다.
    result : [  [position, value, status], [position, value, status], ... ]
    */
    vector<int> sequence_v_type = changeFormat(sequence);
    vector<bool> strikeInfo = informPosition(sequence, strike_array);
    vector<bool> ballInfo = informPosition(sequence, ball_array);
    vector<Info> totalInfo;
    for(int i = 0 ; i < sequence_v_type.size(); i++){
        totalInfo[i].position = i;
        totalInfo[i].value = sequence_v_type[i];
        totalInfo[i].status = strikeInfo[i] ? 's' : ballInfo[i] ? 'b' : 'x';
    }
    return totalInfo;
}


vector<int> genSequences(int sequence, vector<int> strike_array, vector<int> ball_array){
    // total information을 가지고 가능한 모든 수열을 생성한다.
    // 여기서 작업 잠시 중지했습니다. 



}

int main(){
    vector<vector<int>> strike_arrays = chooseStrike(123, 2);
    return 0;
}

/*
    ## 알고리즘 구체화 ##



    vector<int> genSequences(vector<vector<int>> strike_arrays, vector<vector<int>> ball_arrays){
        //위 두 개의 함수에서 생성한 strike_arrays와 ball_arrays를 조합하여 가능한 수열을 생성한다.
    }

    void addSequence(vector<vector<int>> sequences){
        // 생성된 수열을 가능한 수열 리스트에 담아놓는다.
        // 담아 놓을 때, 기존에 있던 수열과 겹치지 않는 수열은 제거한다.
        // ex)
            input : 
            [
                [124,125]
                [143,153]
                [423,523]
            ]
            vector<int> global_vector :
            [124,165,177,143,153]

            updated global_vector :
            [124,143,153]
            }
        

    // 마지막으로, global_vector 안에 있는 원소의 갯수를 반환하면 된다.
    return global_vector.size();
    
*/