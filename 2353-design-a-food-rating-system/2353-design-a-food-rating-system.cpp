class FoodStructure{
    public:
    
    int foodRating;
    string foodName;
    
    FoodStructure(int foodRating, string foodName){
        this->foodRating=foodRating;
        this->foodName=foodName;
    }
    
    /*
bool operator<(const FoodStructure& other) const: This function defines the less-than comparison operator (<) for objects of type FoodStructure.
const FoodStructure& other: This parameter is the other FoodStructure object being compared to the current object. It allows you to compare the properties of the current object (this) with the properties of another FoodStructure object.
    
    */
    bool operator<(const FoodStructure& other) const{
        //if food ratings are same, then sort on the basis of their names
        if(foodRating==other.foodRating){
            return foodName>other.foodName;
        }
        
        //sort on the basis of food rating
        //max_heap
        
        return foodRating<other.foodRating;
    }
};

class FoodRatings {
public:
    unordered_map<string,int> mp1; //for mapping food with it's rating
    unordered_map<string,string> mp2; //for mapping food with it's cuisine
    
    unordered_map<string,priority_queue<FoodStructure>> mp3; 
    //priority queue stores values of data structure FoodStructure
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp1[foods[i]]=ratings[i];
            mp2[foods[i]]=cuisines[i];
            mp3[cuisines[i]].push(FoodStructure(ratings[i],foods[i]));
            
        }
        
    }
    
    void changeRating(string food, int newRating) {
        mp1[food]=newRating;
        string cuisine=mp2[food];
        //insert the new rating again
        mp3[cuisine].push(FoodStructure(newRating,food));
        
    }
    
    string highestRated(string cuisine) {
        auto highestRatedFood= mp3[cuisine].top();
        //fetch the food structure withj maximum rating according to the priority queue
        //since the priority queue doesn't handles the case when the rating is updated and FoodStructure is unique, therefore, we'll discard the Food structure which doesn't contains the updated rating
        
        while(mp1[highestRatedFood.foodName]!=highestRatedFood.foodRating){
            mp3[cuisine].pop(); //remove the top element from the priority queue corresponding to the given cuisine
            highestRatedFood=mp3[cuisine].top(); //store the next top element with maximum rating
            
        }
        
        return highestRatedFood.foodName;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */