# Rocket-Game
rocket game and 2nd version with minmax
Backtracking. A&M game in
which is played on a board of size n, assume 5
as in the shown figure. Each player starts with
n – 2 rockets, one player has rockets in the left
side facing right and one player has rockets on
the top side facing down. Rockets can ONLY
move forward. An exam example of game
play is shown on the side.
You are required to develop the game with
two players. Then add to it a computer player
that uses backtracking to decide the best move. At start, game should offer the choice to play against
another human or against computer. Similar to what we did for a Nim game in the lecture, a game tree
represents all the possible moves from a given state. For example, below is the first two levels of a game
tree for the game state at the start of the game.

To search this tree for a solution, we recursively define a game state to be good or bad as follows:
 A good game state is when (1) a player wins the game or if he can move the opponent to a bad state.
 A bad game state is when (1) the
current player already lost or (2) if
every possible move leads to a good
state to the opponent.
In other words, a non-leaf node in the
game tree is good if it has at least one
bad child, and a non-leaf node is bad if
all its children are good. By induction,
any player that finds the game in a good
state on their turn can win the game,
even if their opponent plays perfectly; on the other hand, starting from a bad state, a player can win only
if their opponent makes a mistake. This recursive algorithm is defined in the side box.
