#pragma once

/**
 * @brief Writes random strings to a file using threads
 *
 * The function uses `mutex` to avoid data races
 *
 * @param num_threads the number of threads to be used
 * @return error status
 */
int write_file(int num_threads);
