#include <vector>
#include <list>

//検索結果
template<class Value_Type>
class FindResult{
public:
    int find_len = 0;   //文字列長
    Value_Type value;   //値
    FindResult(int _find_len, Value_Type& _value){
        find_len = _find_len;
        value    = _value;
    }
};

//ノード
template<class Value_Type>
class Node{
public:
    int leaf_count = 0; //葉の数
    std::list<Value_Type> value; //値

    //ノードに情報を追加
    void set(Value_Type& _value){
        value.push_back(_value);
    }
    //ノードの情報を削除
    void clear(){
        value.clear();
    }
    bool empty(){ return value.empty(); }
    
    ~Node(){
        this->clear();
    }
};


template<class Value_Type>
class Trie_Array{
public:
    int key_size; //最大登録可能文字数
    std::vector<std::vector<int> > graph; //2次元配列でトライ木の遷移を表現
    std::vector<Node<Value_Type> > value; //ノード
    std::vector<int> key_table; //文字置き換えテーブル
    int next_key = 0; //文字置き換えテーブルの登録数

    //初期化
    Trie_Array(int key_size){
        this->key_size = key_size;
        key_table.resize(this->key_size, -1);
        graph.clear();
        add_node();
    }

    //ノード追加
    void add_node(){
        graph.push_back(std::vector<int>(key_size,0)); //グラフ配列追加
        value.push_back(Node<Value_Type>());
    }
    
    //key_arrの前方一致文字列をすべて検索
    std::list<FindResult<Value_Type>> find(const char* key_arr, int size){
        int root = 0;
        int pos;
        std::list<FindResult<Value_Type>> res;

        for(pos = 0; pos < size; pos++){
            unsigned char key = key_arr[pos];
            if(key_table[key] == -1){
                return res;   //存在しない文字があった場合は見つからないので検索終了
            }
            key = key_table[key];
            if(graph[root][key] != 0){
                //次の遷移先がある場合
                root = graph[root][key]; //遷移先へ移動

                if(!value[root].empty()){
                    //検索結果を追加
                    for(auto&& v : value[root].value){
                        FindResult<Value_Type> res_val(pos+1, v);
                        res.push_back(res_val);
                    }
                }
            }else{
                return res;  //次の遷移先がなくなるまで遷移
            }
        }

        return res;
    }

    //トライ木構築
    void insert(const char* key_arr, int size, Value_Type& _value){
        int root = 0;
        int pos;

        for(pos = 0; pos < size; pos++){
            unsigned char key = key_arr[pos];
            if(key_table[key] == -1){
                key_table[key] = next_key++;;   //存在しない文字があった場合は新しく追加
            }
            key = key_table[key];

            if(graph[root][key] != 0){
                root = graph[root][key];//次の遷移先がある場合は遷移
            }else{
                value[root].leaf_count++; //葉の数を追加

                int new_root = graph.size(); //新しいノードID
                graph[root][key] = new_root; //遷移先を追加

                root = new_root;
                add_node(); //ノード作成
            }
        }
        //ノードに情報追加
        value[root].set(_value);
    }
};