#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Twine.h"
#include <stdlib.h>

namespace llvm {
	void llvm_unreachable_internal(const char* msg, const char* file, unsigned line) {
		if (msg) { printf("[%s:%d]%s\n", file ? file : "?", line, msg); }
		abort();
	}

	void report_fatal_error(const char* msg, bool gen_crash_dia) {
		if (msg) { printf("%s\n", msg); }
		abort();
	}

	void report_fatal_error(StringRef msg, bool gen_crash_dia) {
		if (msg.data()) { printf("%s\n", msg.data()); }
		abort();
	}

	void report_fatal_error(const Twine& msg, bool gen_crash_dia) {
		printf("%s\n", msg.str().c_str());
		abort();
	}

	void report_bad_alloc_error(const char* msg, bool gen_crash_dia) {
		printf("%s\n", msg);
		abort();
	}

	raw_ostream& dbgs() { return nulls(); }

}