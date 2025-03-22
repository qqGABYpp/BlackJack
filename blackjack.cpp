#include <bits/stdc++.h>

using namespace std;
// calculate points hand
int calculate_points(vector<pair<string, string>> card) {
    int sum = 0;
    int count_a = 0;  // count ACEs
    for (auto &i: card) {
        if (i.first == "A")
            count_a++;
        else if (i.first == "J" || i.first == "Q" || i.first == "K" || i.first == "10")
            sum += 10;
        else sum += i.first[0] - '0';
    }
    //add ACE in play hand
    for (int i = 0; i < count_a; i++) {
        if (sum <= 10)
            sum += 11;
        else sum += 1;
    }
    return sum;
}

class Player {
    string name;
    int points;
    vector<pair<string, string>> cards;
public:
    Player() {
        this->name = "Dealer";
    }

    Player(const string &name) {
        this->name = name;
    }

    const string &getName() const {
        return name;
    }

    const vector<pair<string, string>> &getCards() const {
        return cards;
    }

    int getPoints() const {
        return points;
    }



    void hit(int index, vector<pair<string, string>> deck) {
        cards.emplace_back(deck[index]);
    }

    void calc() {
        this->points = calculate_points(cards);
    }

    void print() {
        cout << name << ": ";
        for (auto &i: cards)
            cout << i.first << " " << i.second << " ";
        this->points = calculate_points(cards);
        cout << calculate_points(cards) << endl;
    }

    void print_cards() {
        for (auto &i: cards)
            cout << i.first << " " << i.second << " ";
        this->points = calculate_points(cards);
        cout << calculate_points(cards) << endl;
    }
    //condition for split
    bool check_equal() {
        return cards[0].first == cards[1].first;
    }

    void dealer_hand(int &index, vector<pair<string, string>> &deck) {
        points = calculate_points(cards);
        while (points < 17) {
            this->hit(index, deck);
            points = calculate_points(cards);
            index++;
        }
        if (points > 21) {
            cout << name << " bust! ";
            print_cards();
        } else {
            cout << name << " stay with ";
            print_cards();
        }

    }



};


void give_cards_start(vector<Player> &players, vector<pair<string, string>> &deck, int &index) {
    for (int i = 0; i < 2; i++)
        for (auto &c: players) {
            c.hit(index, deck);
            index++;
        }
}

void repete(Player &players, vector<Player> &in_game, vector<Player> &bj, int &index, vector<pair<string, string>> CARDS) {
    players.print();
    if (players.getPoints() == 21 && players.getCards().size() == 2) {
        cout << players.getName() << " has BlackJack! " << players.getPoints() << endl;
        bj.push_back(players);
    } else {
        int input;
        cout << "1. HIT     2. STAY" << endl;
        cin >> input;
        if (input == 1) {
            players.hit(index, CARDS);
            players.calc();
            index++;
            if (players.getPoints() == 21) {
                cout << players.getName() << " has hand of 21! ";
                players.print_cards();
                cout << endl;
                in_game.push_back(players);
            }
            if (players.getPoints() > 21) {
                cout << players.getName() << " bust! ";
                players.print_cards();
            }
            if (players.getPoints() < 21)
                repete(players, in_game, bj, index, CARDS);
        }
        if (input == 2)
            in_game.push_back(players);
    }
}

void split(Player &players, vector<Player> &in_game, vector<Player> &bj, int &index, vector<pair<string, string>> CARDS,
           int poz, int size) {
    players.print();
    int input;
    cout << "1. HIT     2. STAY     3. SPLIT" << endl;
    cin >> input;
    if (input == 1) {
        players.hit(index, CARDS);
        players.print();
        index++;
        if (players.getPoints() == 21) {
            cout << players.getName() << " has hand of 21! ";
            players.print_cards();
            cout << endl;
            in_game.push_back(players);
        }
        if (players.getPoints() > 21) {
            cout << players.getName() << " bust! ";
            players.print_cards();
        }
        if (players.getPoints() < 21)
            repete(players, in_game, bj, index, CARDS);
    }
    if (input == 2)
        in_game.push_back(players);
    if (input == 3) {
        string n1 = players.getName() + " first row", n2 = players.getName() + " second row";
        Player player1(n1), player2(n2);
        player1.hit(poz, CARDS);
        player2.hit(poz + size, CARDS);
        player1.hit(index, CARDS);
        index++;
        player2.hit(index, CARDS);
        index++;
        cout << players.getName() << ": " << endl;
        cout << player1.getName() << ": ";
        player1.print_cards();
        cout << player2.getName() << ": ";
        player2.print_cards();
        repete(player1, in_game, bj, index, CARDS);
        repete(player2, in_game, bj, index, CARDS);

    }
}


int main() {
    vector<pair<string ,string>> CARDS = {
            {"A","Heart"}, {"A","Romb"}, {"A","Club"}, {"A","Spade"},
            {"2","Heart"}, {"2","Romb"}, {"2","Club"}, {"2","Spade"},
            {"3","Heart"}, {"3","Romb"}, {"3","Club"}, {"3","Spade"},
            {"4","Heart"}, {"4","Romb"}, {"4","Club"}, {"4","Spade"},
            {"5","Heart"}, {"5","Romb"}, {"5","Club"}, {"5","Spade"},
            {"6","Heart"}, {"6","Romb"}, {"6","Club"}, {"6","Spade"},
            {"7","Heart"}, {"7","Romb"}, {"7","Club"}, {"7","Spade"},
            {"8","Heart"}, {"8","Romb"}, {"8","Club"}, {"8","Spade"},
            {"9","Heart"}, {"9","Romb"}, {"9","Club"}, {"9","Spade"},
            {"10","Heart"}, {"10","Romb"}, {"10","Club"}, {"10","Spade"},
            {"J","Heart"}, {"J","Romb"}, {"J","Club"}, {"J","Spade"},
            {"Q","Heart"}, {"Q","Romb"}, {"Q","Club"}, {"Q","Spade"},
            {"K","Heart"}, {"K","Romb"}, {"K","Club"}, {"K","Spade"},
            };

    srand(time(0));
    random_shuffle(CARDS.begin(), CARDS.end());
    vector<Player> players, players_in_game, bj_players;

    int nr;
    cout << "Introdu numarul de jucatori(Dealer-el exista deja): " << endl;
    cin >> nr;
    for (int i = 0; i < nr; i++) {
        cout << "Introdu numele jocatorului " << i + 1 << ": " << endl;
        string name;
        cin >> name;
        players.emplace_back(Player(name));
    }
    players.emplace_back(Player());
    int index = 0;
    give_cards_start(players, CARDS, index);

    for (auto &i: players)
        i.print();
    cout << endl;

    for (int i = 0; i < players.size() - 1; i++) {
        if (players[i].getPoints() == 21) {
            cout << players[i].getName() << " has BlackJack!" << endl;
            bj_players.push_back(players[i]);
        } else if (players[i].check_equal())
            split(players[i], players_in_game, bj_players, index, CARDS, i, players.size());
        else
            repete(players[i], players_in_game, bj_players, index, CARDS);
    }

    for (auto &i: players_in_game)
        i.print();
    cout << endl;
    for (auto &i: bj_players)
        i.print();
    cout << endl;
    Player dealer = players[players.size() - 1];
    if (dealer.getPoints() == 21) {
        for (auto &i: players_in_game)
            cout << dealer.getName() << " beats " << i.getName() << " -- Score " << dealer.getPoints() << " - "
                 << i.getPoints() << endl;
        for (auto &i: bj_players)
            cout << dealer.getName() << " pushes to (BlackJack both) " << i.getName() << " -- Score "
                 << dealer.getPoints() << " - " << i.getPoints() << endl;
    } else {
        dealer.dealer_hand(index, CARDS);
        if (dealer.getPoints() > 21)
            for (auto &i: players_in_game)
                cout << dealer.getName() << " defeated by " << i.getName() << " -- Score " << dealer.getPoints() << " - "
                     << i.getPoints() << endl;
        else
            for (auto &i: players_in_game) {
                if (dealer.getPoints() > i.getPoints())
                    cout << dealer.getName() << " beats " << i.getName() << " -- Score " << dealer.getPoints() << " - "
                         << i.getPoints() << endl;
                else if (dealer.getPoints() == i.getPoints())
                    cout << dealer.getName() << " pushes to " << i.getName() << " -- Score " << dealer.getPoints()
                         << " - "
                         << i.getPoints() << endl;
                else
                    cout << dealer.getName() << " defeated by " << i.getName() << " -- Score " << dealer.getPoints()
                         << " - "
                         << i.getPoints() << endl;
            }
    }
}
