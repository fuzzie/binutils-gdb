# Check 64bit PTWRITE instructions

	.text
_start:
	ptwrite %ecx
	ptwritel %ecx
	ptwrite %rcx
	ptwriteq %rcx
	ptwrite (%rcx)
	ptwritel (%rcx)
	ptwriteq (%rcx)

	.intel_syntax noprefix
	ptwrite ecx
	ptwrite rcx
	ptwrite DWORD PTR [rcx]
	ptwritel DWORD PTR [rcx]
	ptwrite QWORD PTR [rcx]
