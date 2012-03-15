#! /bin/sh

# test if echo command interprets -n option
xxx=`echo -n`

if [ -z "$xxx" ]
  then
    eopt=-n
    eend=
  else
    eopt=
    eend="""\c"""
fi

# ---------------------------------------------------------------------------
# "hook000" - If this hook file exists, the contents of this file is
# printed very first.
cat >hook000 <<END
<!-- Generated by SmallEiffel short html style hooks -->
<html>
<head>
<title>Eiffel class THISCLASS</title>
</head>
<body>
<pre>
END

# "hook010" - If this hook file exists, and if the processed class is
# an expanded one, the contents of this file is printed before the
# class name to replace the default string "expanded class interface
# ".
echo $eopt '<strong>expanded class interface</strong> '$eend > hook010

# "hook011" - If this hook file exists, and if the processed class is
# an deferred one, the contents of this file is printed before the
# class name to replace the default string "deferred class interface
# ".
echo $eopt '<strong>deferred class interface</strong> '$eend > hook011

# "hook012" - If this hook file exists, and if the processed class is
# an ordinary one (not deferred nor expanded) the contents of this
# file is printed before the class name to replace the default string
# "class interface ".
echo $eopt '<strong>class interface</strong> '$eend > hook012

# "hook013" _ If this hook file exists, the contents of this file is
# printed before the class name whatever the kind of class (expanded,
# deferred or ordinary) to replace the default empty string "".
rm -f hook013

# "hook014" - If this hook exists, the contents of the file is printed
# after the class name to replace the default string "%N".
rm -f hook014

# "hook015" - If this hook file exists, and if a class header comment
# is present, this file is printed once before the heading class
# comment.
echo $eopt '<em>'$eend > hook015

# "hook016" - If this hook file exists, and if an heading comment is
# present, the contents of this file is printed to replace the default
# string " -- " at the beginning of each comment line.
rm -f hook016

# "hook017" - If this hook file exists, and if an heading comment is
# present, the contents of this file is printed to replace the default
# string "%N" at the end of each comment line.
rm -f hook017

# "hook018" - If this hook file exists, and if a class heading comment
# is present, the contents of this file is printed once after the
# heading comment.
echo $eopt '</em>
'$eend > hook018

# "hook019" - If this hook file exists, and if the processed class has
# no heading comment, this file is printed once.
echo $eopt '
'$eend > hook019

# ---------------------------------------------------------------------------
# 2.2. Changing output of the creation list

# "hook100" - If it exists, this file is printed before the creation
# list to replace the default string "creation%N".
echo $eopt '<strong>creation</strong>
'$eend > hook100

# "hook101" - If it exists, this file is printed after the creation
# list to replace the default empty string "".
rm -f hook101

# "hook102" - If it exists, this file is printed when class has no
# creation list.
rm -f hook102

# ---------------------------------------------------------------------------
# 2.3. Changing output of the feature list

# "hook200" - If exists, printed before the feature list when option
# -sort is selected to replace the default string "feature(s)%N".
echo $eopt '<strong>feature(s)</strong>
'$eend > hook200

# "hook201" - If exists, printed after the feature list when option
# -sort is selected to replace the default empty string "".
echo $eopt '
'$eend > hook201

# "hook202" - If exists, printed before each feature list with no
# heading comment to replace the default string "feature(s) from ".
echo $eopt '<strong>feature(s) from </strong>'$eend > hook200

# "hook203" - If exists, printed after the class name of "hook202" to
# replace the default string "%N".
echo $eopt '
<em>'$eend > hook203

# "hook204" - If exists, printed before a feature list with a heading
# comment to replace the default string "feature(s) from ".
echo $eopt '<strong>feature(s) from </strong>'$eend > hook204

# "hook205" - If exists, printed after the class name introduced at
# "hook204" to replace the default string "%N".
echo $eopt '
<em>'$eend > hook205

# "hook206" - If exists, printed before each line of the feature list
# comment to replace the default string " -- ".
rm -f hook206

# "hook207" - If exists, printed after each line of the feature list
# comment to replace the default string "%N".
rm -f hook207

# "hook208" - If exists, printed after a feature list comment to
# replace the default empty string "".
echo $eopt '</em>
'$eend > hook208

# ---------------------------------------------------------------------------
# 2.4. Changing output of a feature signature

# "hook300" - If this hook exists, the contents of this file is
# printed before each feature to replace the default string " ".
rm -f hook300

# "hook301" - If this hook exists, the contents of this file is
# printed once when the feature has no arguments to replace the
# default empty string "".
rm -f hook301

# "hook302" - If this hook exists, the contents of this file is
# printed once when the feature has arguments to replace the default
# string " (".
rm -f hook302

# "hook303" - If this hook exists, the contents of this file is
# printed when the feature has arguments to replace the default string
# " ;".
rm -f hook303

# "hook304" - If this hook exists, the contents of this file is
# printed when the feature has arguments to replace the default string
# ", ".
rm -f hook304

# "hook305" - If this hook exists, the contents of this file is
# printed when the feature has arguments to replace the default string
# ": ".
rm -f hook305

# "hook306" - If this hook exists, the contents of this file is
# printed once when the feature has arguments to replace the default
# string ")".
rm -f hook306

# "hook307" - If this hook exists, the contents of this file is
# printed once when the feature has no result to replace the default
# string "%N".
rm -f hook307

# "hook308" - If this hook exists, the contents of this file is
# printed once before the result type of the feature to replace the
# default string ": ".
rm -f hook308

# "hook309" - If this hook exists, the contents of this file is
# printed once after the result type of the feature to replace the
# default string "%N".
rm -f hook309

# ---------------------------------------------------------------------------
# 2.5. Changing output of a feature comment

# "hook310" - If this hook file exists, and if a feature has a heading
# comment, this file is printed once before the comment.
echo $eopt '<em>'$eend > hook310

# "hook311" - If this hook file exists, and if a feature has a heading
# comment, the contents of this file is printed to replace the default
# string " -- " at the beginning of each comment line.
rm -f hook311

# "hook312" - If this hook file exists, and if a feature has a heading
# comment, the contents of this file is printed to replace the default
# string "%N" at the end of each comment line.
rm -f hook312

# "hook313" - If this hook file exists, and if a feature has a heading
# comment, the contents of this file is printed once after this
# comment.
echo $eopt '</em>'$eend > hook313

# "hook314" - If this hook file exists, and if a feature has no
# heading comment, the contents of this file is printed.
rm -f hook314

# ---------------------------------------------------------------------------
# 2.6. Changing output of require clauses
# 2.6.1. For the header of a require clause

# "hook400" - If this hook file exists, and if a feature has no
# require assertion, the contents of this file is printed to replace
# the default empty string "".
rm -f hook400

# "hook401" - If this hook file exists, and if a feature has one
# require assertion, the contents of this file is printed before the
# latest inherited assertion to replace the default string "require%N".
echo $eopt '      <strong>require</strong>
'$eend > hook401

# "hook402" - If this hook file exists, and if a feature has more than
# one require assertion, the contents of this file is printed before
# the require assertion to replace the default string " require else%N".
echo $eopt '      <strong>require else</strong>
'$eend > hook401

# "hook403" - If this hook file exists, and if a feature has at least
# one require assertion, the contents of this file is printed to
# finish the job (once after the last printed require assertion) to
# replace the default empty string "".
rm -f hook403

# "hook412" - If exists, printed when a require clause has no heading
# comment to replace the default empty string "".
rm -f hook412

# "hook413" - If exists, printed once before the require clause
# heading comment to replace the default empty string "".
echo $eopt '<em>'$eend > hook413

# "hook414" - If exists, printed before each line of the heading
# comment to replace the default string " -- ".
rm -f hook414

# "hook415" - If exists, printed after each line of the heading
# comment to replace the default string "%N".
rm -f hook415

# "hook416" - If exists, printed once after the require clause heading
# comment.
echo $eopt '</em>'$eend > hook416

# "hook417" - If exists, printed when a require clause has no
# assertion to replace the default empty string "".
rm -f hook417

# "hook418" - If exists, printed once before the first assertion of a
# require clause to replace the default empty string "".
rm -f hook418

# "hook433" - If exists, printed once after the last assertion of a
# require clause to replace the default empty string "".
rm -f hook433

# "hook434" - If exists, printed to finish a require clause to replace
# the default empty string "".
rm -f hook434

# 2.6.2. For each assertion in a require clause

# "hook419" - If exists, printed before each assertion of a require
# clause to replace the default string " ".
rm -f hook419

# "hook420" - If exists, printed when an assertion has no tag to
# replace the default empty string "".
rm -f hook420

# "hook421" - If exists, printed before a tag to replace the default
# empty string "".
rm -f hook421

# "hook422" - If exists, printed after a tag to replace the default
# string ": ".
rm -f hook422

# "hook423" - If exists, printed when the assertion has no expression
# to replace the default empty string "".
rm -f hook423

# "hook424" - If exists, printed before the expression to replace the
# default empty string "".
rm -f hook424

# "hook425" - If exists, printed after the expression (except for the
# last assertion) to replace the default string ";".
rm -f hook425

# "hook426" - If exists, printed when an assertion has no comment to
# replace the default string "%N".
rm -f hook426

# "hook427" - If exists, printed once before the assertion comment to
# replace the default empty string "".
echo $eopt '<em>'$eend > hook427

# "hook428" - If exists, printed before each line oqf the expression
# comment to replace the default string " -- ".
rm -f hook428

# "hook429" - If exists, printed after each line of the expression
# comment to replace the default string "%N".
rm -f hook429

# "hook430" - If exists, printed once after the assertion's comment to
# replace the default string "".
echo $eopt '</em>'$eend > hook430

# "hook431" - If exists, printed after the assertion to replace the
# default empty string "".
rm -f hook431

# 2.6.3. For the last assertion in a require clause Same hook file
# list as described in section 2.6.2 except "hook425" which becomes :

# "hook432" - If exists, printed after the last expresion to replace
# the default empty string "".
rm -f hook432

# ---------------------------------------------------------------------------
# 2.7. Changing output of ensure clauses
# 2.7.1. For the header of the ensure clause

# "hook500" - If this hook file exists, and a feature has no ensure
# clause, the contents of this file is printed to replace the default
# empty string "".
rm -f hook500

# "hook511" - If this hook file exists, the contents of this file is
# printed before each ensure clause to replace the default string "ensure%N".
echo $eopt '      <strong>ensure</strong>
'$eend > hook511

# "hook512" - If exists, printed when ensure clause has no heading
# comment to replace default empty string "".
rm -f hook512

# "hook513" - If exists, printed once before the ensure clause heading
# comment to replace the default empty string "".
echo $eopt '<em>'$eend > hook513

# "hook514" - If exists, printed before each line of the heading
# comment to replace the default string " -- ".
rm -f hook514

# "hook515" - If exists, printed after each line of the heading
# comment to replace the default string "%N".
rm -f hook515

# "hook516" - If exists, printed once after the ensure clause heading
# comment.
echo $eopt '</em>'$eend > hook516

# "hook517" - If exists, printed when an ensure clause has no
# assertion to replace the default empty string "".
rm -f hook517

# "hook518" - If exists, printed once before the first assertion of
# the ensure clause to replace the default empty string "".
rm -f hook518

# "hook533" - If exists, printed once after the last assertion of the
# ensure clause to replace the default empty string "".
rm -f hook533

# "hook534" - If exists, printed to finish the ensure clause to
# replace the default empty string "".
rm -f hook534

# 2.7.2. For each assertion in the ensure assertion

# "hook519" - If exists, printed before each assertion of the ensure
# clause to replace the default string " ".
rm -f hook519

# "hook520" - If exists, printed when an assertion has no tag to
# replace the default empty string "".
rm -f hook520

# "hook521" - If exists, printed before a tag to replace the default
# empty string "".
rm -f hook521

# "hook522" - If exists, printed after a tag to replace the default
# string ": ".
rm -f hook522

# "hook523" - If exists, printed when the assertion has no expression
# to replace the default empty string "".
rm -f hook523

# "hook524" - If exists, printed before the expression to replace the
# default empty string "".
rm -f hook524

# "hook525" - If exists, printed after the expresion (except for the
# last assertion) to replace the default string ";".
rm -f hook525

# "hook526" - If exists, printed when an assertion has no comment to
# replace the default string "%N".
rm -f hook526

# "hook527" - If exists, printed once before the assertion comment to
# replace the default empty string "".
echo $eopt '<em>'$eend > hook527

# "hook528" - If exists, printed before each line of the expression comment to replace the default string " -- ".
rm -f hook528

# "hook529" - If exists, printed after each line of the expression
# comment to replace the default string "%N".
rm -f hook529

# "hook530" - If exists, printed once after the assertion's comment to
# replace the default string "".
echo $eopt '</em>'$eend > hook530

# "hook531" - If exists, printed after the assertion to replace the
# default empty string "".
rm -f hook531

# 2.7.3. For the last assertion in the ensure clause Same hook files
# list as described in section 2.7.2 except "hook525" which becomes:

# "hook532" - If exists, printed after the last expresion to replace
# the default empty string "".
rm -f hook532

# ---------------------------------------------------------------------------
# 2.8. Changing output after each feature

# "hook599" - If exists, printed after each feature to replace the
# default empty string "".
echo $eopt '
'$eend > hook599

# ---------------------------------------------------------------------------
# 2.9. Changing output of the class invariant
# 2.9.1. For the header of the class invariant

# "hook800" - If this hook file exists, and when no class invariant
# exists, the contents of this file is printed to replace the default
# empty string "".
rm -f hook800

# "hook811" - If this hook file exists, the contents of this file is
# printed before the class invariant to replace the default string
# "invariant%N".
echo $eopt '<strong>invariant</strong>
'$eend > hook811

# "hook812" - If exists, printed when class invariant has no heading
# comment to replace default empty string "".
rm -f hook812

# "hook813" - If exists, printed once before the invariant heading
# comment to replace the default empty string "".
echo $eopt '<em>'$eend > hook813

# "hook814" - If exists, printed before each line of the heading
# comment to replace the default string " -- ".
rm -f hook814

# "hook855" - If exists, printed after each line of the heading
# comment to replace the default string "%N".
rm -f hook855

# "hook816" - If exists, printed once after the invariant heading
# comment.
echo $eopt '</em>'$eend > hook816

# "hook817" - If exists, printed when class invariant has no assertion
# to replace the default empty string "".
rm -f hook817

# "hook818" - If exists, printed once before the first assertion of
# the class invariant to replace the default empty string "".
rm -f hook818

# "hook833" - If exists, printed once after the last assertion of the
# class invariant to replace the default empty string "".
rm -f hook833

# "hook834" - If exists, printed to finish the class invariant to
# replace the default empty string "".
rm -f hook834

# 2.9.2. For each assertion in the class invariant

# "hook819" - If exists, printed before each assertion of the class
# invariant to replace the default string " ".
rm -f hook819

# "hook820" - If exists, printed when an assertion has no tag to
# replace the default empty string "".
rm -f hook820

# "hook821" - If exists, printed before a tag to replace the default
# empty string "".
rm -f hook821

# "hook822" - If exists, printed after a tag to replace the default
# string ": ".
rm -f hook822

# "hook823" - If exists, printed when the assertion has no expression
# to replace the default empty string "".
rm -f hook823

# "hook824" - If exists, printed before the expression to replace the
# default empty string "".
rm -f hook824

# "hook825" - If exists, printed after the expresion (except for the
# last assertion) to replace the default string ";".
rm -f hook825

# "hook826" - If exists, printed when an assertion has no comment to
# replace the default string "%N".
rm -f hook826

# "hook827" - If exists, printed once before the assertion comment to
# replace the default empty string "".
echo $eopt '<em>'$eend > hook827

# "hook828" - If exists, printed before each line of the expression
# comment to replace the default string " -- ".
rm -f hook828

# "hook829" - If exists, printed after each line of the expression
# comment to replace the default string "%N".
rm -f hook829

# "hook830" - If exists, printed once after the assertion's comment to
# replace the default string "".
echo $eopt '</em>'$eend > hook830

# "hook831" - If exists, printed after the assertion to replace the
# default empty string "".
rm -f hook831

# 2.9.3. For the last assertion in the class invariant Same hook
# files list as described in section 2.9.2 except "hook825" which
# becomes :

# "hook832" - If exists, printed after the last expresion to replace
# the default string ";".
rm -f hook832

# ---------------------------------------------------------------------------
# 2.10. Changing output of the class interface footer

# "hook900" - When exists, printed once before class footer to replace
# the default empty string "".
echo $eopt '
<strong>'$eend > hook900

# "hook901" - When exists, printed once at the end of an expanded
# class before the class name to replace the default "end of expanded".
rm -f hook901

# "hook902" - When exists, printed once at the end of a deferred class
# before the class name to replace the default "end of deferred ".
rm -f hook902

# "hook903" - When exists, printed once at the end of an ordinary (not
# expanded nor deferred) class, before the class name to replace the
# default string "end of ".
rm -f hook903

# "hook904" - When exist, printed just before the class name to
# replace the default empty string "".
rm -f hook904

# "hook905" - When exists, the contents of this file is printed after
# the class name to replace the default string "%N".
rm -f hook905

# "hook999" - If this hook file exists, the contents of this file is
# printed once to finish the job.
cat >hook999 <<END
</pre>
</body>
</html>
END

# ---------------------------------------------------------------------------
# 2.11. Changing the output of class names

# "Bcn" - When exists, printed Before each class name.
echo $eopt '<a href="CLASSREF">'$eend > Bcn

# "Acn" - When exists, printed After each class name.
echo $eopt '</a>'$eend > Acn

# "Ucn" - To replace the Underscore character in a class name.
rm -f Ucn

# ---------------------------------------------------------------------------
# 2.12. Changing the output of a type mark

# "Btm" - When exists, printed Before each type mark.
# echo $eopt '<em>'$eend > Btm
rm -f Btm

# "Atm" - When exists, printed After each type mark.
# echo $eopt '</em>'$eend > Atm
rm -f Atm

# "open_sb" - To replace the opening square bracket (default "[").
rm -f open_sb

# "close_sb" - To replace the closing square bracket (default "]").
rm -f close_sb

# "fgl_sep" - To replace the default comma "," in a formal generic argument list.
rm -f fgl_sep

# "tm_blank" - To replace a blank character in a type mark.
rm -f tm_blank

# "tm_sep" - To replace default string "," as a separator in a generic list.
rm -f tm_sep

# "like" - To replace the default string "like ".
rm -f like

# "expanded" - To replace the default string "expanded ".
rm -f expanded

# ---------------------------------------------------------------------------
#  2.14. Changing the output of an argument name

# "Ban" - When exists, printed Before each argument name.
# echo $eopt '<tt>'$eend > Ban
rm -f Ban

# "Aan" - When exists, printed after each argument name.
# echo $eopt '</tt>'$eend > Aan
rm -f Aan

# "Uan" - To replace the Underscore character in an argument name.
rm -f Uan

# ---------------------------------------------------------------------------
# 2.15. Changing the output of tag name

# "Btag" - When exists, printed Before each tag name.
rm -f Btag

# "Atag" - When exists, printed after each tag name.
rm -f Atag

# "Utag" - To replace the Underscore character in a tag name.
rm -f Utag

# ---------------------------------------------------------------------------
# 2.19. Changing the output of comments line

# "BECL" - Before Each Comment Line. This hook is applied to all
# comments whatever the kind of comment. If exists, printed before the
# contents of each line of each comment (usually after the default
# string "-- ").
rm -f BECL

# "AECL" - After Each Comment Line. This hook is applied to all
# comments whatever the kind of comment. If exits, printed after the
# contents of each line of each comment (usually, printed before the
# default "%N").
rm -f AECL

# "Ucomment" - To replace the Underscore character in a comment.
rm -f Ucomment

# "op_quote" - To replace the default opening quote mark "`".
echo $eopt '</em>'$eend > op_quote

# "cl_quote" - To close an "op_quote" to replace the closing quote mark "'".
echo $eopt '<em>'$eend > cl_quote