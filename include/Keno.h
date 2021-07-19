#include <iostream>
#include <random>

using namespace std;

class Keno
{
public:
    float balance, bet;
    int rounds, spots;
    int *first_spot, *last_spot;
    int *generate_winners_numbers();
    int get_hits(int *first_winner_number);
    float get_payoff(int hits, bool print_payoff);
    void run_bets();
    void print_header();
    void print_footer();
    Keno(float _balance, int _rounds, int *_first_spot, int *_last_spot);
};

Keno::Keno(float _balance, int _rounds, int *_first_spot, int *_last_spot)
{
    this->balance = _balance;
    this->rounds = _rounds;
    this->first_spot = _first_spot;
    this->last_spot = _last_spot;
    this->bet = _balance / _rounds;
    this->spots = _last_spot - _first_spot;
}

int *Keno::generate_winners_numbers()
{
    static int r[20];
    srand((unsigned)time(NULL));
    int rand_number;
    int i = 0;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> get_random_number(1, 80);

    while (i < 20)
    {
        rand_number = get_random_number(rng);
        bool can_insert = 1;
        // verifica se o numero ja foi sorteado antes
        for (int j = 0; j <= i; j++)
        {
            if (r[j] == rand_number)
                can_insert = 0;
        }
        if (can_insert)
        {
            r[i] = rand_number;
            cout << r[i] << " ";
            i++;
        }
    };

    return r;
}

int Keno::get_hits(int *first_winner_number)
{
    int size = this->last_spot - this->first_spot;
    int hits = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (*(this->first_spot + i) == *(first_winner_number + j))
            {
                cout << *(this->first_spot + i) << " ";
                hits++;
            }
        }
    }
    return hits;
}

float Keno::get_payoff(int hits, bool print_payoff = 0)
{
    float payoff_array[15][16] = {
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 2, 6, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 1, 3, 15, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 1, 2, 3, 30, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 0.5, 1, 6, 12, 36, 100, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720, 0, 0, 0, 0, 0, 0, 0},
        {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200, 0, 0, 0, 0, 0, 0},
        {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800, 0, 0, 0, 0, 0},
        {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000, 0, 0, 0, 0},
        {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000, 0, 0, 0},
        {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000, 0, 0},
        {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500, 0},
        {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};
    if (print_payoff)
    {
        cout << "   ----------+-----------" << endl;
        cout << "   Hits      | Retorno" << endl;
        for (int i = 0; i <= this->spots; i++)
        {
            cout << "   " << i << "         | " << payoff_array[(this->spots) - 1][i] << endl;
        }
        return 0;
    }
    return payoff_array[(this->spots) - 1][hits];
}

void Keno::run_bets()
{
    this->print_header();
    for (int i = 0; i < this->rounds; i++)
    {
        cout << "   ------------------------------------------------------------" << endl;
        cout << "   Esta é a rodada #" << i + 1 << " de " << this->rounds << ", sua aposta é $" << this->bet << ". Boa sorte!" << endl;
        cout << "   Os números sorteados são: [ ";
        int *first_winner_number = this->generate_winners_numbers();
        cout << "]" << endl
             << endl;
        cout << "   Você acertou os números [ ";
        int hits = this->get_hits(first_winner_number);
        cout << "], um total de " << hits << " hit de " << this->spots << endl;
        float payoff = this->get_payoff(hits);
        cout << "   Sua taxa de retorno é " << payoff << ", assim você sai com: $" << this->bet * payoff << endl;
        this->balance += ((this->bet * payoff) - this->bet);
        cout << "   Você possui um total de: $" << this->balance << " créditos." << endl;
    }
    this->print_footer();
}

void Keno::print_header()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Aposta lida com sucesso!" << endl;
    cout << "Você apostará um total de $" << this->balance << " créditos." << endl;
    cout << "Jogará um total de " << this->rounds << " rodadas, apostando $" << this->bet << " créditos por rodada" << endl;
    cout << "Sua aposta tem " << this->spots << " números, eles são: [ ";
    for (int i = 0; i < this->spots; i++)
    {
        cout << *(this->first_spot + i) << " ";
    }
    cout << "]" << endl;
    this->get_payoff(0, 1);
}

void Keno::print_footer()
{
    cout << "Fim das rodadas!" << endl;
    cout << "--------------------------------------------------------------------" << endl
         << endl;
    cout << "======= Sumário =======" << endl;
    cout << "Você gastou um total de $" << this->bet * this->rounds << " créditos" << endl;
    float difference = this->balance - (this->bet * this->rounds);
    if (difference >= 0)
        cout << "Hooray! você ganhou $" << difference << " créditos!" << endl;
    else
        cout << "Você perdeu $" << (difference) * -1 << " créditos :(" << endl;
    cout << "Você está saindo do jogo com um total de $" << this->balance << " créditos." << endl;
}