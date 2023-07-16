class Solution {
public:
    vector<int> res;
    int target_mask;
    unordered_map<string, int> dp;
    void helperfunc(vector<int>& people_skill, int index, vector<int>& temp_res, int mask){
        if(index==people_skill.size()){
            if(mask==target_mask){ //1111
                if(res.size()==0 || res.size()>=temp_res.size()){
                    res=temp_res;
                }
            }
                return ;
            }
      
            
           string key= to_string(index)+to_string(mask);
            if(dp.find(key)!=dp.end()){
                if(dp[key]<=temp_res.size()){
                    return;
                }
            }
        
          if(res.size()!=0 && res.size()<=temp_res.size()){
            return; //if the res is already min
        }
        
        
        helperfunc(people_skill,index+1,temp_res,mask); //do not take
        
        if(mask==(mask | people_skill[index])){ //if the person does not contain any new skill set
            return;
        }
        
        
        temp_res.push_back(index);
        
        helperfunc(people_skill,index+1,temp_res,(mask|people_skill[index])); //take
        
        temp_res.pop_back();
        
        dp[key]= (temp_res.size()!=0)? temp_res.size():-1; //store the temp_res size for that respective people as well as skill_set
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        int m=people.size();
        
        //make an array of bits such the instead of binary, it's corresponding decimal value is stored at the ith people index
        //this will indicate the number of skills that a person has
        unordered_map<string,int> skills;
        
        
        
        for(int i=0;i<n;i++){
            skills[req_skills[i]]=i; //for creating a map of skills along with their index in the req_skill vector
        }
        
        vector<int> people_skill;
        
        for(auto& x: people){
            int skill_bit=0; //storing the mask
            for(auto& y: x){ //y is a skill
                skill_bit=skill_bit | (1<<skills[y]);
            }
            people_skill.push_back(skill_bit); //store the mask inside the people_skill //110
        }
        
        target_mask=pow(2,n)-1;
        vector<int> temp_res; //stores the different combinations of answer vector
        helperfunc(people_skill,0,temp_res,0);  //index and mask are initially 0
        
        return res;
        
        
    }
};