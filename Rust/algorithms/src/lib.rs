pub mod pathfinder;
use std::fs;
use serde_json::{Value, Error};
use std::collections::HashMap;

fn read_json_file(path: String) -> Result<Value, Error> {
    let file = fs::read_to_string(path)
        .expect("file can't be opened");
    serde_json::from_str(&file[..])
}

enum Graph<Node> where Node: Eq {
    AdjacencyList(HashMap<Node, Vec<Node>>)
}

struct AdjacencyList {
    name: String,
    edges: HashMap<String, Vec<String>>
}


fn get_graph(file_path: String, id: u32) -> Graph<String> {
    let data = read_json_file(String::from("data/graphs.json"))
        .expect("Bad json file");
    let data_type = data["type"];
    if matches!(data_type, Value(Value::String(String::from("AdjacencyList")))) {
        
    }
    match data["type"] {
        String(String::from("AdjacencyList")) => {
            todo!()
        }
        _ => panic!()
    }
    todo!()
}

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
