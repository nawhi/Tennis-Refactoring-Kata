#include <string>
#include <map>

std::map<int, std::string> SCORES = {
    {0, "Love"},
    {1, "Fifteen"},
    {2, "Thirty"},
    {3, "Forty"}
};

std::string getWinningPlayer(int scoreDifference) {
    return (scoreDifference > 0) ? "player1" : "player2";
}

const std::string tennis_score(int p1Score, int p2Score) {
    if (p1Score == p2Score)
    {
        return (p2Score < 3) 
            ? SCORES.at(p2Score) + "-All"
            : "Deuce";
    }
    
    if (p1Score >= 4 || p2Score >= 4)
    {
        int difference = p1Score - p2Score;
        std::string winningPlayer = getWinningPlayer(difference);
        return (abs(difference) == 1) 
            ? "Advantage " + winningPlayer
            : "Win for " + winningPlayer;
    }

    return SCORES.at(p1Score) + "-" + SCORES.at(p2Score);
}
