static lin p_first;			/* 1st line number */
static lin p_newfirst;			/* 1st line number of replacement */
static lin p_ptrn_lines;		/* # lines in pattern */
static lin p_repl_lines;		/* # lines in replacement text */
static lin p_end = -1;			/* last line in hunk */
static lin p_max;			/* max allowed value of p_end */
static lin p_prefix_context;		/* # of prefix context lines */
static lin p_suffix_context;		/* # of suffix context lines */
static lin p_input_line;		/* current line # from patch file */
static lin hunkmax = INITHUNKMAX;	/* size of above arrays */
static lin p_bline;			/* line # of p_base */
static lin p_sline;			/* and the line number for it */
static lin p_hunk_beg;			/* line number of current hunk */
static lin p_efake = -1;		/* end of faked up lines--don't free */
static lin p_bfake = -1;		/* beg of faked up lines */
static char *scan_linenum (char *, lin *);
static void next_intuit_at (file_offset, lin);
static void skip_to (file_offset, lin);
    next_intuit_at (file_pos, 1);
	    diff_type == GIT_BINARY_DIFF ? "a git binary diff" :
	    if (lstat (inname, &instat) == 0)
    file_offset this_line = 0;
    file_offset first_command_line = -1;
    lin fcl_line = 0; /* Pacify `gcc -W'.  */
    bool this_is_a_command = false;
    bool stars_this_line = false;
    bool git_diff = false;
    enum diff retval;
    p_timestamp[OLD].tv_sec = p_timestamp[NEW].tv_sec = -1;
	char *s;
	char *t;
	file_offset previous_line = this_line;
	bool last_line_was_command = this_is_a_command;
	bool stars_last_line = stars_this_line;
	size_t indent = 0;
	    free (p_name[OLD]);
	    free (p_name[OLD]);
	    free (p_name[INDEX]);
	    p_name[INDEX] = fetchname (s+6, strippath, (char **) 0, NULL);
	else if (strnEQ (s, "diff --git ", 11))
	  {
	    char const *t;

	    if (! ((free (p_name[OLD]),
		    (p_name[OLD] = parse_name (s + 11, strippath, &t)))
		   && ISSPACE (*t)
		   && (free (p_name[NEW]),
		       (p_name[NEW] = parse_name (t, strippath, &t)))
		   && (t = skip_spaces (t), ! *t)))
	      for (i = OLD; i <= NEW; i++)
		{
		  free (p_name[i]);
		  p_name[i] = 0;
		}
	    git_diff = true;
	  }
	else if (git_diff && strnEQ (s, "deleted file mode ", 18))
	  p_says_nonexistent[NEW] = 2;
	else if (git_diff && strnEQ (s, "new file mode ", 14))
	  p_says_nonexistent[OLD] = 2;
	else if (git_diff && strnEQ (s, "GIT binary patch", 16))
	  {
	    p_start = this_line;
	    p_sline = p_input_line;
	    retval = GIT_BINARY_DIFF;
	    goto scan_exit;
	  }
		struct timespec timestamp;
		timestamp.tv_sec = -1;
		free (p_name[NEW]);
		if (timestamp.tv_sec != -1)
	    struct timespec ti = p_timestamp[OLD];
	      p_says_nonexistent[OLD] = 1 + ! p_timestamp[OLD].tv_sec;
	      p_says_nonexistent[NEW] = 1 + ! p_timestamp[NEW].tv_sec;
	    if (! ((p_name[OLD] || ! p_timestamp[OLD].tv_sec)
		   && (p_name[NEW] || ! p_timestamp[NEW].tv_sec))
	      p_says_nonexistent[OLD] = 1 + ! p_timestamp[OLD].tv_sec;
	      lin saved_p_bline = p_bline;
		p_says_nonexistent[NEW] = 1 + ! p_timestamp[NEW].tv_sec;
	    if (! ((p_name[OLD] || ! p_timestamp[OLD].tv_sec)
		   && (p_name[NEW] || ! p_timestamp[NEW].tv_sec))
	      else if (lstat (p_name[i], &st[i]) != 0)
		&& (i == NONE || S_ISREG (st[i].st_mode))
	    inerrno = lstat (inname, &instat) == 0 ? 0 : errno;
	    if (inerrno || S_ISREG (instat.st_mode))
	      maybe_reverse (inname, inerrno, inerrno || instat.st_size == 0);
next_intuit_at (file_offset file_pos, lin file_line)
skip_to (file_offset file_pos, lin file_line)
    FILE *i = pfp;
    FILE *o = stdout;
    int c;
scan_linenum (char *s0, lin *linenum)
  lin n = 0;
      lin new_n = 10 * n + (*s - '0');
    char *s;
    lin context = 0;
    size_t chars_read;
	lin repl_beginning = 0;		/* index of --- line */
	lin fillcnt = 0;	/* #lines of missing ptrn or repl */
	lin fillsrc;		/* index of first line to copy */
	lin filldst;		/* index of first missing line */
	bool repl_could_be_missing = true;
	lin repl_patch_line;		/* input line number for same */
	lin repl_context;		/* context for same */
	lin ptrn_prefix_context = -1;	/* lines in pattern prefix context */
	lin ptrn_suffix_context = -1;	/* lines in pattern suffix context */
	lin repl_prefix_context = -1;	/* lines in replac. prefix context */
	lin ptrn_copiable = 0;		/* # of copiable lines in ptrn */
	lin repl_copiable = 0;		/* Likewise for replacement.  */
	file_offset line_beginning = file_tell (pfp);  /* file pos of the current line */
	lin fillsrc;  /* index of old lines */
	lin filldst;  /* index of new lines */
	int i;
	lin min, max;
	lin i;
  FILE *fp = pfp;
  int c;
  size_t i;
  char *b;
  size_t s;
  FILE *fp = pfp;
  int c;
  file_offset line_beginning = file_tell (fp);
    lin i;
    lin n;
    char *s;
lin
lin
lin
lin
lin
lin
lin
pch_line_len (lin line)
pch_char (lin line)
pfetch (lin line)
pch_write_line (lin line, FILE *file)
lin
    file_offset beginning_of_this_line;
    FILE *pipefp = 0;
    size_t chars_read;
  lin old = 1;
  lin new = p_ptrn_lines + 1;