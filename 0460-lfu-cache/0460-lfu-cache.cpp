class LFUCache {
    struct Node {
        int key, val, freq;
    };

    int cap, mn;
    unordered_map<int, list<Node>::iterator> mp;
    unordered_map<int, list<Node>> freqList;

public:
    LFUCache(int capacity) {
        cap = capacity;
        mn = 0;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        auto it = mp[key];
        Node node = *it;

        freqList[node.freq].erase(it);

        if (freqList[node.freq].empty()) {
            freqList.erase(node.freq);
            if (mn == node.freq)
                mn++;
        }

        node.freq++;
        freqList[node.freq].push_front(node);
        mp[key] = freqList[node.freq].begin();

        return node.val;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (mp.count(key)) {
            mp[key]->val = value;
            get(key);
            return;
        }

        if (mp.size() == cap) {
            auto node = freqList[mn].back();
            mp.erase(node.key);
            freqList[mn].pop_back();

            if (freqList[mn].empty())
                freqList.erase(mn);
        }

        mn = 1;
        freqList[1].push_front({key, value, 1});
        mp[key] = freqList[1].begin();
    }
};