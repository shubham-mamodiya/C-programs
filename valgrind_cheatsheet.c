/*
 * valgrind_cheatsheet.c
 *
 * Comprehensive Valgrind Usage Cheat Sheet
 * Use this as a reference for memory debugging
 * and performance profiling tools.
 */

#include <stdio.h>

int main() {
    printf("Valgrind Cheat Sheet Loaded\\n");
    return 0;
}

/* -----------------------------------------------------------
 * INSTALLATION
 * -----------------------------------------------------------
 * Arch Linux:   sudo pacman -S valgrind
 * Debian/Ubuntu: sudo apt install valgrind
 * Fedora:       sudo dnf install valgrind
 */

/* -----------------------------------------------------------
 * BASIC MEMORY CHECKS
 * -----------------------------------------------------------
 * Run a program with memcheck (default tool):
 *   valgrind ./a.out
 *
 * Show full leak details:
 *   valgrind --leak-check=full ./a.out
 *
 * Show origin of uninitialized values:
 *   valgrind --track-origins=yes ./a.out
 *
 * Show reachable blocks too:
 *   valgrind --leak-check=full --show-leak-kinds=all ./a.out
 *
 * Add suppression of noisy system reports:
 *   valgrind --leak-check=full --suppressions=/path/file.supp ./a.out
 */

/* -----------------------------------------------------------
 * ANALYZING OUTPUT
 * -----------------------------------------------------------
 * "Invalid read": reading memory you shouldn't.
 * "Invalid write": writing out-of-bounds.
 * "Use of uninitialized value": using garbage values.
 * "Definitely lost": actual memory leak.
 * "Indirectly lost": memory pointed to by leaked pointers.
 * "Still reachable": not a leak, but not freed.
 */

/* -----------------------------------------------------------
 * PERFORMANCE PROFILING WITH CALLGRIND
 * -----------------------------------------------------------
 * Run program with callgrind:
 *   valgrind --tool=callgrind ./a.out
 *
 * Visualize (on Linux):
 *   kcachegrind callgrind.out.<pid>
 *
 * Disable instrumentation for speed:
 *   valgrind --tool=callgrind --instr-atstart=no ./a.out
 *   callgrind_control -i on
 */

/* -----------------------------------------------------------
 * CACHE PROFILER: CACHEGRIND
 * -----------------------------------------------------------
 *   valgrind --tool=cachegrind ./a.out
 *
 * View results:
 *   cg_annotate cachegrind.out.*
 *
 * Useful flags:
 *   --branch-sim=yes   (simulate branch predictor)
 */

/* -----------------------------------------------------------
 * THREAD DEBUGGING WITH DRD
 * -----------------------------------------------------------
 *   valgrind --tool=drd ./a.out
 * Detects:
 *   - data races
 *   - locking order violations
 */

/* -----------------------------------------------------------
 * THREAD DEBUGGING WITH HELGRIND
 * -----------------------------------------------------------
 *   valgrind --tool=helgrind ./a.out
 *
 * Detects:
 *   - race conditions
 *   - inconsistent lock usage
 */

/* -----------------------------------------------------------
 * SPECIAL USEFUL OPTIONS
 * -----------------------------------------------------------
 * Track file descriptors:
 *   --track-fds=yes
 *
 * Show children processes:
 *   --trace-children=yes
 *
 * Run faster (less accurate):
 *   --smc-check=all-non-file
 */

/* -----------------------------------------------------------
 * TYPICAL COMMAND TEMPLATES
 * -----------------------------------------------------------
 * Debug everything:
 *   valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out
 *
 * Debug and log to file:
 *   valgrind --log-file=valgrind.log --leak-check=full ./a.out
 *
 * Ignore specific false positives:
 *   valgrind --gen-suppressions=all ./a.out
 */

/* -----------------------------------------------------------
 * GOOD PRACTICES
 * -----------------------------------------------------------
 * - Always compile with debug symbols: gcc -g file.c -o file
 * - Use small test inputs to avoid slowdowns
 * - Fix errors from top to bottom (one bug can cause many messages)
 * - Use suppression files when system libraries cause noise
 */
