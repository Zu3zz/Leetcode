class Leaderboard:

    def __init__(self):
        self.lb = [0]*1000
        

    def addScore(self, playerId: int, score: int) -> None:
        self.lb[playerId]+=score
        

    def top(self, K: int) -> int:
        tmp = []
        for i in self.lb:
            if i != 0:
                tmp.append(i)
        tmp.sort(reverse=True)
        ret = 0
        for i in range(K):
            ret+=tmp[i]
        return ret
        

    def reset(self, playerId: int) -> None:
        self.lb[playerId] = 0
        


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)