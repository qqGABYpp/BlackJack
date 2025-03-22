Blackjack Game Simulation in C++
This project is a console-based Blackjack game written in C++, designed to simulate a real casino-style Blackjack experience. The game is built using object-oriented programming (OOP) principles, focusing on game logic, card deck management, player actions, and dealer AI behavior.

 Features & Game Mechanics
 Deck & Card Management
Uses a standard 52-card deck, represented as a vector<pair<string, string>>, where each card has a value (A, 2-10, J, Q, K) and a suit (Hearts, Diamonds, Clubs, Spades).

Implements random shuffling (random_shuffle()) at the start of the game to ensure fair gameplay.

Cards are dealt sequentially from the shuffled deck.

 Player Actions & Game Logic
Each player starts with two cards.

Players can choose from the following actions:
 Hit – Draw another card.
 Stand – Keep the current hand and pass the turn.
 Split – If the first two cards are identical, the player can split them into two separate hands.

 Hand Scoring System
Uses the function calculate_points() to evaluate the total value of a player's hand.

Face cards (J, Q, K, 10) are worth 10 points.

Aces (A) can be counted as 1 or 11, depending on what benefits the hand.

The hand automatically busts if it exceeds 21 points.

 Dealer Automated Play
The dealer follows standard Blackjack rules:

Hits until the total hand value reaches 17 or higher.

If the dealer busts, all remaining players win automatically.

 Winning & Game Outcome
If a player gets exactly 21 with two cards, it's a Blackjack and an instant win (unless the dealer also has Blackjack).

If a player busts (exceeds 21), they automatically lose.

If the dealer and a player have the same score, it results in a push (tie).

If the player's score is higher than the dealer’s, the player wins.

 Technical Implementation
 Object-Oriented Design
The game is structured around a Player class, which handles:
✔ Storing player details (name, hand, points).
✔ Card drawing (hit method) – Adds a new card from the deck to the player’s hand.
✔ Hand evaluation – Calculates and updates hand points dynamically.
✔ Game decisions – Determines whether the player should continue or stop.

 Recursive Functions for Player Actions
The functions repete() and split() use recursion to handle player decisions dynamically.

Players interactively choose actions, and the game responds accordingly.

 Console-Based User Interaction
Uses cin/cout to prompt players for input and display results.

Displays each player’s cards and score at every turn.

Dealer’s hand is partially hidden until it is their turn to play.

 Code Structure & Flow
1. Game Initialization

The deck is created and shuffled.

Players are added to the game (with dealer included automatically).

Each player is dealt two cards.

2. Player Turns

Each player decides to hit, stand, or split.

If a player reaches 21 points or busts, their turn ends.

Splitting allows players to play two separate hands.

3. Dealer’s Turn

The dealer draws cards until they reach 17+ points.

If the dealer busts, all remaining players win.

4. Determining Winners

The dealer’s final hand is compared to each player’s hand.

Results are displayed for each player: win, lose, or push (tie).

