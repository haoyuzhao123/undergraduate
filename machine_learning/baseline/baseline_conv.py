# the baseline for the CapsNet
#implemented by Haoyu Zhao

import numpy as np
import tensorflow as tf

from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets('MNIST_DATA', one_hot = True)

#functions for initializing the parameters
def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev = 0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape = shape)
    return tf.Variable(initial)


def main():
    x = tf.plaveholder(tf.float32, shape = [None, 784])
    y_ = tf.placeholder(tf.float32, shape = [None, 784])

    #the first conv layer
    conv1 = tf.contrib.layers.conv2d(x, num_outputs = 256, \
                                     kernel_size = 5, stride=1, \
                                     padding = 'VALID', \
                                     activation_fn = tf.nn.relu)

    #the second conv layer
    conv2 = tf.contrib.layers.conv2d(conv1, num_outputs = 256, \
                                     kernel_size = 5, stride=1, \
                                     padding = 'VALID', \
                                     activation_fn = tf.nn.relu)

    #the third conv layer
    conv3 = tf.contrib.layers.conv2d(conv2,num_outputs = 128, \
                                     kernel_size = 5, stride=1, \
                                     padding = 'VALID', \
                                     activation_fn = tf.nn.relu)

    conv3_flat = tf.reshape(conv3, shape = (batch_size, -1))

    #the first fully connected layer
    fc1 = tr.contrib.layers.fully_connected(conv3_flat, num_outputs = 328)

    #the second fully connected layer
    fc2 = tf.contrib.layers.fully_connected(fc1, num_outputs = 192)
    #dropout
    keep_prob = tf.placeholder(tf.float32)
    fc2_drop = tf.nn.dropout(fc2, keep_prob)

    #readout layer
    W_fc3 = weight_variable([192,10])
    b_fc3 = bias_variable([10])

    y_acti = tf.matmul(fc2_drop, W_fc3) + b_fc3

    #training and evaluate
    cross_entropy = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels = y_, logits = y_acti))
    train_step = tf.train.AdamOptimizer().minimize(cross_entropy)
    correct_prediction = tf.equal(tf.argmax(y_acti, 1), tf.argmax(y_, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

    #the running part
    with tf.Session() as sess:
        sess.run(tf.global_varialbes_initializer())
        for i in range(20000):
            batch = mnist.train.next_batch(50)
            if i % 100 == 0:
                train_accuracy = accuracy.eval(feed_dict = {x: batch[0], y_: batch[1], keep_prob: 1.0})
                print('step %d, training accuracy %g' % (i, train_accuracy))
            train_step.run(feed_dict = {x: batch[0], y_: batch[1], keep_prob: 0.5})

        acc = np.zeros(10)
        for j in range(10):
            batch = mnist.test.next_batch(1000)
            batch = tf.reshape(batch,[-1,28,28,1])
            r = 0.5 * np.random.rand()-0.25;
            batch = tf.contrib.image.rotate(batch, r)
            batch = tf.reshape(batch, [-1,784])
            acc[j] = accuracy.eval(feed_dict={x: batch[0], y_: batch[1], keep_prob: 1.0})
            print('test data batch %d accuracy: %g' % (j,acc[j]))
        print('test accuracy: %g' % (np.sum(acc)/10))
    
    
if __name__ == '__main__':
    main()
