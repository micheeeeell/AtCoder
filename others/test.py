import itertools

for x in itertools.permutations("いせうちゅかにとつぶ"):
    # for i in len(x):
    #     if x[i] == 'ゅ' :
    #         if i == 0:
    #             ok = false
    #             continue
    #         if x[i+1] != 'う':
    #             ok = false
    #             continue
    #         if x[i-1] != 'ち' and i != 2 and x[i-1] != 'に' :
    #             ok = false
    #             continue
    # if bool(ok) :
        print("つ",x[0],x[1],"り",x[2],x[3],x[4],x[5],"く",x[6],x[7],x[8],x[9])

# for x in itertools.permutations("abcd"):
#     print(x)