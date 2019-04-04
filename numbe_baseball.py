'''
    def chooseStrike(sequence, strike_number)
        output : possible strike lists

        ex)
        input : sequence = 123, strike_number = 1;
        output : [[1], [2], [3]]

    def chooseBall(sequence, strike_list, ball_number)
        sequence = 123, strike_list가 = [1]이 주어졌고, ball_number가 1이 주어진다면,
        이를 바탕으로 가능한 ball_lists를 출력한다.
        output : [[2],[3]]

    def genInformation(sequence, strike_list, ball_list) 
        sequence = 123, strike_list = [1] , ball_list = [2]
        와 같이 주어지면 
         1) strike_list에 있는 데이터는 고정시켜서 result_list에 저장. ex) result_list = [1, x, x]
         2) ball_list에 있는 데이터의 포지션 이외에 배치를 시킨다.
            즉, strike를 제외한 전체 포지션에서 가능한 순열 중,
            해당 위치에 데이터가 있는 것을 제거하면 된다. 
            ex) if sequence = 123, strike_list = [], ball_list = [1,2]
                일단 info_ball_list를 만든다. 이 list는 ball_list의 data가 sequence에서 어떤 index에 있는지를 담고 있다.
                    ex) info_ball_list = [[1,0], [2,1]]
                3자리 중, ball_number 만큼의 자리를 선택 후, 그 자리에 ball_list에 있는 데이터를 배치한다.
                모든 경우를 possible_sequences = [[1,2,x], [2,1,x], [1,x,2] , [2,x,1] , ... ] 와 같이 나타낸다.
                이 때, 각 possible_sequences를 info_ball_list와 비교해서 생성된 수열이 ball_list와 겹치는 것이 없는 경우에만 
                result_list에 값을 추가한다.


                
                
                




    

'''

def solution(baseball):

    answer = 0
    return answer

baseball = [[123,1,1], [356,1,0], [327,2,0], [489,0,1]]
# [sequence, strike_number, ball_number]

list(map(int, str(12345)))


solution(baseball)