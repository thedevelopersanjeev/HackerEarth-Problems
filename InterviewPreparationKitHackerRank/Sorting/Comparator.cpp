bool comp(Player p1, Player p2){
    if(p1.score>p2.score) return true;
    if(p1.score==p2.score) return p1.name<p2.name;
    return false;
}
vector<Player> comparator(vector<Player> players) {
    sort(players.begin(),players.end(), comp);
    return players;
}