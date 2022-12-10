#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 
#include <stack> 
using namespace std;

using pii = pair<int, int>; // for the key, value test cases

struct tCache{
  unordered_map<int,int> cache; // key/value
  stack<int> last_keys; // when maximum capacity is reached
  int size; // maximum size
};

// apply the operation op over the cache
void cache(int key, int value, tCache& c, string op) {
  // create 
  if (op == "new"){
    c.size = value; // the size will be in the value arg
    c.cache = {};
    c.last_keys = {};
  }
  // insert
  else if(op == "insert"){
    // check if the key already exists
    auto it = c.cache.find(key); 
    if (it == c.cache.end()) { // the key doesnt exists
      if (c.size == c.cache.size()){ // reach the maximum size allowed
        auto last_key = c.cache.find(c.last_keys.top()); 
        c.last_keys.pop();
        c.cache.erase(last_key); // remove the last key used
      }
    }
    c.cache.insert_or_assign(key, value); // insert or update the key/value
    c.last_keys.push(key); // push the last key used
  }
  // remove
  else if(op == "remove"){
    auto it = c.cache.find(key); // return the iterator to an existent key
    if (it != c.cache.end())
      c.cache.erase(it); // remove the key if exists
  }
}

int main() {
  vector<string> op_codes{"new", "insert", "insert", "insert", "insert", "remove", "insert"}; 
  vector<int> keys{ 0, 1, 1, 2, 4, 3, 5}; 
  vector<int> values{ 3, 2, 3, 4, 5, 3, 6}; 
  
  tCache my_cache;// the cache we gonna use
  for (int i = 0; i < op_codes.size(); i++){
    cout << i << ") op: " << op_codes[i] << ", key: " << keys[i] << ", value:" << values[i] << endl;
    cache(keys[i], values[i], my_cache, op_codes[i]);
    // show the unordered map
    for (auto x: my_cache.cache)
      cout << x.first << " " << x.second << endl; 
    cout << endl;
  }
  
  return 0;
}
