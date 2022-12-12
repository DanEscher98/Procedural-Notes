use std::collections::{BinaryHeap, HashMap};
use std::cmp::{Reverse, Ordering};

#[derive(Eq, PartialEq)]
struct CheckPoint {
    name: String,
    from: Option<String>,
    cost: u32
}

impl Ord for CheckPoint {
    fn cmp(&self, other: &Self) -> Ordering {
        // other.cost < self.cost => self > cost
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for CheckPoint {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        // It doesn't make sense compare nodes that doesn't share the from
        if self.from == other.from {
            return Some(self.cmp(other))
        }
        None
    }
}

fn next_destinations<T>(trails: impl Iterator<Item = T>, start: String) -> impl Iterator<Item = T> {
    trails.filter_map(move |trail| {
        if trail.start == start {
            Some(trail)
        } else {
            None
        }
    })
}

pub fn optimal_path<P, T>(
	start: String,
	destination: String,
	player: &P,
	trails: impl Iterator<Item = T>,
	cost_function: impl Fn(&P, &T) -> Option<u32>,
) -> Option<u32> {
    let mut frontier: BinaryHeap<CheckPoint> = BinaryHeap::new();
    let mut history_from: HashMap<&String, (Option<String>, u32)> = HashMap::new();
    
    let c_point = CheckPoint {
        name: start,
        from: None,
        cost: 0
    };
    frontier.push(c_point);
    history_from.insert(&c_point.name, (c_point.from, c_point.cost));

    while !frontier.is_empty() {

    }

    todo!()
}
