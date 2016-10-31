import nltk

class Analyzer():
    """Implements sentiment analysis."""

    # lists to download dictionaries
    pos_words = []
    neg_words = []

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""
        # download dictionaries
        try:
            f_positive = open(positives, "r")
            for line in f_positive:
                Analyzer.pos_words.append(line)
            f_negative = open(negatives, "r")
            for line in f_negative:
                Analyzer.neg_words.append(line)
        finally:
            f_positive.close()
            f_negative.close()
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        text = text.split(" ")
        score = 0
        # analyze text word by word
        for word in text:
            if Analyzer.pos_words.count(word+"\n"):
                score += 1
            elif Analyzer.neg_words.count(word+"\n"):
                score -= 1
        return score