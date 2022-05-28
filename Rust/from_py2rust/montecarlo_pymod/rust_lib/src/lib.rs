use num_format::{Locale, ToFormattedString};
use rand::prelude::{thread_rng, Rng};
use std::thread;
use std::time::Instant;

pub fn monte_carlo(iterations: u32) -> (f64, String) {
    let num_cpus = num_cpus::get() as u32;
    let now = Instant::now();

    let mut handles = vec![];
    for _ in 0..num_cpus {
        handles.push(thread::spawn(move || {
            let mut rng = thread_rng();
            let mut inside: u64 = 0;
            for _ in 0..iterations {
                let a = rng.gen::<f64>();
                let b = rng.gen::<f64>();
                let c = a.powf(2f64) + b.powf(2f64);
                if c <= 1f64 {
                    inside += 1;
                }
            }
            inside
        }));
    }

    let mut total_inside: u64 = 0;
    for h in handles {
        total_inside += h.join().unwrap();
    }

    let total_iterations = iterations as u64 * num_cpus as u64;
    let aprox_pi = total_inside as f64 / total_iterations as f64 * 4.0;
    let calculations_str = ((total_iterations as f64 / now.elapsed().as_secs_f64()) as u64)
        .to_formatted_string(&Locale::en);
    (aprox_pi, calculations_str)
}
