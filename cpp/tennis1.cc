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
    int tempScore=0;
    if (p1Score==p2Score)
    {
        score = (p2Score < 3) 
            ? SCORES.at(p2Score) + "-All"
            : "Deuce";
    }
    else if (p1Score>=4 || p2Score>=4)
    {
        int minusResult = p1Score-p2Score;
        if (minusResult==1) score ="Advantage player1";
        else if (minusResult ==-1) score ="Advantage player2";
        else if (minusResult>=2) score = "Win for player1";
        else score ="Win for player2";
    }
    else
    {
        for (int i=1; i<3; i++)
        {
            if (i==1)
            {
                tempScore = p1Score;
            }
            else
            {
                score += "-"; 
                tempScore = p2Score;
            }
            score += SCORES.at(tempScore);
        }
    }
    return score;
}
