
def canPlace(stalls, dist)-> int:
    ctr = 1;
    placed = stalls[0]
    for i in range(1, len(stalls)):
        if( abs(placed - stalls[i]) >= dist):
            ctr += 1
            placed = stalls[i]
    
    return ctr
            


def aggressiveCows(stalls, k):
    mini = min(stalls)
    maxi = max(stalls)
    low = 1
    high = maxi - mini

    if k == 2:
        return high

    while low <= high:
        mid = int((low + high)/2)
        check = canPlace(stalls, mid)

        if check >= k:
            low = mid + 1;
        else:
            high = mid - 1;

    return high


def main():
    stalls = [4, 2, 1, 3, 6]
    k = 2
    print(aggressiveCows(stalls, k))

main()
    

