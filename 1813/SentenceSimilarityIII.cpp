/*
https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06
*/

class Solution {
public:

    vector<string> splitAtSpaces(string &sentence){
        int sz=sentence.size(), idx=0;
        string curr="";
        vector<string>res;
        while(idx<sz){
            if(sentence[idx]==' '){
                res.push_back(curr);
                curr="";
                idx++;
            } else{
                curr+=sentence[idx];
                idx++;
            }
        }
        if(curr.size()>=1) res.push_back(curr);
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>split1=splitAtSpaces(sentence1);
        vector<string>split2=splitAtSpaces(sentence2);
        if(split1==split2) return true;
        if(split2.size()==1&&split2[0]==split1[split1.size()-1]) return true;
        if(split1.size()==split2.size()) return false;
        if(split1.size()<split2.size()) swap(split1, split2);
        bool flag=false;
        int tochkidx=split1.size()-1;
        for(int i=split2.size()-1; i>=0; --i){
            if(split2[i]!=split1[tochkidx]){
                flag=true;
                break;
            } else{
                tochkidx--;
            }
        }
        if(!flag) return true;
        bool alreadySeen=false, alreadyWritten=false;
        for(int i=0; i<split1.size(); ++i){
            if(split2.size()>split1.size()) return false;
            string curr=split1[i];
            if(i>=split2.size()){
                if(alreadySeen&&alreadyWritten){
                    int count=split1.size()-split2.size();
                    int idx1=split1.size()-1;
                    bool flag2=false;
                    while(count--){
                        if(split2[split2.size()-1]!=split1[idx1]){
                            flag2=true;
                            break;
                        } else idx1--;
                    }
                    if(!flag2) return true;
                    return false;
                }
                return true;
            } else if(split2[i]!=curr){
                string tochk=split2[i];
                auto itr=find(split1.begin(), split1.end(), tochk);
                if(itr==split1.end()) return false;
                if(alreadySeen&&alreadyWritten){
                    return false;
                }
                if(!alreadyWritten) alreadyWritten=true;
                int curri=i;
                while(true){
                    if(curri>=split1.size()) break;
                    if(split1[curri]!=split2[curri]){
                        auto itr=split2.begin()+curri;
                        split2.insert(itr, split1[curri]);
                        curri++;
                    } else break;
                }
            } else{
                alreadySeen=true;
            }
        }    
        return true;
    }
};