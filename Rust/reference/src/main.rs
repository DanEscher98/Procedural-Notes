use rand::distributions::Standard;
use rand::prelude::*;

fn main() {
    let n = 100;
    let randv: Vec<f32> = thread_rng().sample_iter(&Standard).take(n).collect();
    println!("{:?}", randv);
    println!("Hello, world!");
}
