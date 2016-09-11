class Solution {
private:
    static bool cmp(tuple<string, string, double>& a, tuple<string, string, double>& b) {
        string samin = min(get<0>(a), get<1>(a));
        string samax = max(get<0>(a), get<1>(b));
        string sbmin = min(get<0>(b), get<1>(b));
        string sbmax = max(get<0>(b), get<1>(b));
        if (samin != sbmin) {
            return samin < sbmin;
        } else {
            return samax < sbmax;
        }
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        vector<tuple<string, string, double>> input;
        for (int i = 0; i < values.size(); i++) {
            input.push_back(make_tuple(equations[i].first, equations[i].second, values[i]));
        }
        sort(input.begin(), input.end(), cmp);
        
        vector<unordered_map<string, double>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < input.size(); i++) {
            if (!res.empty() && res.back().count(get<0>(input[i]))) {
                unordered_map<string, double>& temp = res.back();
                temp[get<1>(input[i])] = temp[get<0>(input[i])] / get<2>(input[i]);
                mp[get<1>(input[i])] = res.size() - 1;
            } else if (!res.empty() && res.back().count(get<1>(input[i]))) {
                unordered_map<string, double>& temp = res.back();
                temp[get<0>(input[i])] = temp[get<1>(input[i])] * get<2>(input[i]);
                mp[get<0>(input[i])] = res.size() - 1;
            } else {
                unordered_map<string, double> temp;
                temp[get<1>(input[i])] = 1.0;
                temp[get<0>(input[i])] = get<2>(input[i]);
                res.push_back(temp);
                mp[get<0>(input[i])] = res.size() - 1;
                mp[get<1>(input[i])] = res.size() - 1;
            }
        }
        
        vector<double> output;
        for (int i = 0; i < query.size(); i++) {
            if (mp.count(query[i].first) && mp.count(query[i].second) && mp[query[i].first] == mp[query[i].second]) {
                int ind = mp[query[i].first];
                output.push_back(res[ind][query[i].first] / res[ind][query[i].second]);
            } else {
                output.push_back(-1.0);
            }
        }
        return output;
    }
};
