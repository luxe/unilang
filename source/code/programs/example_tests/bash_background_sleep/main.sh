#!/bin/bash

# This is a simple test that violates the bazel test encyclopedia by
# spawning subprocesses in their own sessions.  This happens to run
# the sleeps in the background so that they themselves are not session
# leaders.

# When executed locally, it completes quickly:
# $ ./bazel test --test_output=all --test_timeout=-1 :sh-test-setsid

# When executed on buildfarm:
# $ ./bazel test --test_output=all --test_timeout=-1 --remote_executor=<host> sh-test-setsid
# (15:45:43) INFO: Remote build results -<host>/build/6b1aebab-f258-4f82-99fe-e3c2bf75987b
# INFO: Invocation ID: 0a629e0f-028f-4d17-bb9c-f56e9326718c
# INFO: Build option --test_timeout has changed, discarding analysis cache.
# INFO: Analyzed target :sh-test-setsid (1 packages loaded, 4005 targets configured).
# INFO: Found 1 test target...
# [4 / 5] Testing :sh-test-setsid; 1101s remote
# ^C

# the test will run until its sleeps complete. In this case, note that the
# test has clearly exceeded its timeout, but buildfarm is not cleaning it
# up.

set -euo pipefail

for     (( i = 0 ; i < 4 ; i++ ))
do      echo "$i"
        setsid sh -c "sleep 7200 &"
done

exit 0