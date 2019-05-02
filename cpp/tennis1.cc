#include <string>
#include <map>

std::map<int, std::string> SCORES = {
    {0, "Love"},
    {1, "Fifteen"},
    {2, "Thirty"},
    {3, "Forty"}
};

const std::string tennis_score(int p1Score, int p2Score) {
    std::string score = "";
    if (p1Score == p2Score)
    {
        score = (p2Score < 3) 
            ? SCORES.at(p2Score) + "-All"
            : "Deuce";
    }
    else if (p1Score >= 4 || p2Score >= 4)
    {
        int difference = p1Score - p2Score;
        if (difference == 1) score = "Advantage player1";
        else if (difference == -1) score = "Advantage player2";
        else if (difference >= 2) score = "Win for player1";
        else score = "Win for player2";
    }
    else
    {
        int tempScore = 0;
        
        tempScore = p1Score;
        score += SCORES.at(tempScore);

        tempScore = 0;
        score += "-";
        tempScore = p2Score;
        score += SCORES.at(tempScore);
    }
    return score;
}
