import nltk
#from nltk.tokenize import TweetTokenizer

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
                Analyzer.pos_words.append(line.replace('\n',''))
            f_negative = open(negatives, "r")
            for line in f_negative:
                Analyzer.neg_words.append(line.replace('\n',''))
        finally:
            f_positive.close()
            f_negative.close()
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        text = tokenizer.tokenize(text)
        score = 0
        # analyze text word by word
        for word in text:
            if Analyzer.pos_words.count(word.lower()):
                score += 1
            elif Analyzer.neg_words.count(word.lower()):
                score -= 1
        return score