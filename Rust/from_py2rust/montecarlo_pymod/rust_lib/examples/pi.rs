use montecarlo_pymod::monte_carlo;
use std::time::Instant;

fn main() {
    let now = Instant::now();
    let (pi, calculations_str) = monte_carlo(1_000_000);
    println!("{:.2}s runtime", now.elapsed().as_secs_f64());
    println!("{}", pi);
    println!("{} calculations per second", calculations_str);
}
