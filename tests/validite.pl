#!/usr/bin/perl -w

use v5.10;
use warnings;
use strict;
use autodie;

my $application="../build/ensisepc";
my $validateur="../build/validateur";
my @valg=("", "valgrind -q", "valgrind -q --tool=drd",
	  "valgrind -q --tool=helgrind");

die "Usage: validite.pl numero\n" unless defined $ARGV[0];

my $nbtest = shift @ARGV;
my $valgrind = $valg[$nbtest];

my $command="${valgrind} ${application} | grep '##' | $validateur ";
system $command;
if ( ($? >> 8) != 0 ) {
    say "echec du test $nbtest: $command";
    exit -1;
}
