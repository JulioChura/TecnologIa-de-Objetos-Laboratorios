#include <iostream>
#include <list>

using namespace std;

int countChange(int money, int coins[], int n) {
    
    if (money == 0) return 1; // cuando se encuentra una combinación 
    if (money < 0 ) return 0;
    if ( money > 0 && n <= 0  ) return 0;

    int sinMoneda = countChange(money, coins, n-1);
    int conMoneda = countChange(money-coins[n-1], coins, n);

    return sinMoneda + conMoneda;

}

int main() {
    int coin = 100000;
    int coins[] = {1,5,10,25};
    int n = sizeof(coins)/ sizeof(coins[0]);
    cout << "countChange(4, [1,2]) = " << countChange(coin, coins, n) << endl;
    return 0;
}

