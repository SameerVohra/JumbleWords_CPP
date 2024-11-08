#include<bits/stdc++.h>
using namespace std;

string scramble(string word){
  string scrambelled = "";
  unordered_set<int>st;

  int n = word.length();

  srand(time(0));

  while(st.size()!=n){
    int randIdx = rand()%n;
    st.insert(randIdx);
  }

  for(auto i: st){
    scrambelled+=word[i];
  }
  
  return scrambelled;

}

void printGuessedWords(vector<string>& arr){
  int n = arr.size();
  for(int i=0; i<n-1; i++) cout << arr[i] << ", ";
  cout << arr[n-1];
  cout << endl;
}

int main(){
  
vector<string> words = {
    "apple", "banana", "melon", "grape", "raspberry", "blackberry", "strawberry", "pineapple", "blueberry", "cherry",
    "lettuce", "carrot", "potato", "onion", "broccoli", "cauliflower", "cabbage", "spinach", "cucumber", "zucchini",
    "tomato", "chili", "peas", "greenbean", "pumpkin", "corn", "eggplant", "squash", "celery", "beet",
    "rose", "lily", "daisy", "orchid", "violet", "tulip", "sunflower", "chrysanthemum", "magnolia", "lavender",
    "clover", "ivy", "basil", "oregano", "rosemary", "mint", "garlic", "ginger", "turmeric", "cinnamon",
    "peanut", "cashew", "walnut", "almond", "hazelnut", "macadamia", "pistachio", "cherry", "apricot", "peach",
    "milk", "cheese", "yogurt", "butter", "cream", "eggnog", "icecream", "sourcream", "mozzarella", "cheddar",
    "ketchup", "mustard", "mayo", "sriracha", "vinegar", "soy", "honey", "jam", "peanutbutter", "syrup",
    "salt", "pepper", "sugar", "flour", "rice", "quinoa", "oats", "barley", "cornmeal", "pasta",
    "burger", "pizza", "sushi", "taco", "sandwich", "hotdog", "salad", "steak", "friedchicken", "grilledfish",
    "pancakes", "waffles", "cookie", "cake", "pie", "donut", "cupcake", "muffin", "brownie", "fudge",
    "smoothie", "juice", "coffee", "tea", "water", "lemonade", "milkshake", "icedtea", "hotchocolate", "soda",
    "pasta", "lasagna", "spaghetti", "ramen", "soup", "chili", "curry", "stew", "stirfry", "burrito"
};

  srand(time(0));
  int n = words.size();
  int randIdx = rand()%n;

  string word = words[randIdx];

  int numGuesses = 4;

  string scrambelledWord = scramble(word);
  int wrongGuesses = 0;

  vector<string> guessedWords;
  bool isFound = false;

  while(numGuesses!=wrongGuesses){
    cout << "Guesses Remaining: " << numGuesses-wrongGuesses << endl;
    cout << "Jumbelled Word is: " << scrambelledWord << endl;
    string guess;
    cout << "Guess the word: ";
    cin >> guess;

    if(guess!=word){
      guessedWords.push_back(guess);
      printGuessedWords(guessedWords);
      wrongGuesses++;
    }
    else{
      cout << endl << "YOU WIN!!" << endl;
      isFound = true;
      break;
    }

    cout << endl;
  }

  if(!isFound){
    cout << endl << "YOU LOST" << endl;
    cout << "The word was: " << word << endl;
  }
}
